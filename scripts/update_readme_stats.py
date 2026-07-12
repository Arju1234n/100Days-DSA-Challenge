import os
import re

# Directory of the repo
REPO_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
README_PATH = os.path.join(REPO_DIR, 'README.md')

CODE_EXTENSIONS = {'.cpp', '.py', '.java', '.go', '.rs', '.js', '.ts', '.c', '.h'}

def parse_file_header(file_path):
    """
    Parses the C++ style or script header to extract the Problem Name and Difficulty.
    Falls back to title-cased filename if not found.
    """
    problem_name = None
    difficulty = "Medium"
    try:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read(1000)  # Only read the first 1000 chars for header efficiency
            
        name_match = re.search(r'Problem Name:\s*(.*)', content)
        if name_match:
            problem_name = name_match.group(1).strip(' []\r\n\t')
            
        diff_match = re.search(r'Difficulty:\s*(.*)', content)
        if diff_match:
            difficulty = diff_match.group(1).strip(' []\r\n\t')
    except Exception as e:
        print(f"Error parsing header of {file_path}: {e}")
        
    if not problem_name:
        # Fallback: two_sum.cpp -> Two Sum
        base = os.path.splitext(os.path.basename(file_path))[0]
        problem_name = base.replace('_', ' ').replace('-', ' ').title()
        
    return problem_name, difficulty

def update_topic_readme(dir_name):
    """
    Updates the checklist in the individual topic's README.md (e.g. 01-Arrays/README.md)
    by cross-referencing files in the directory.
    """
    dir_path = os.path.join(REPO_DIR, dir_name)
    readme_path = os.path.join(dir_path, 'README.md')
    if not os.path.isdir(dir_path) or not os.path.isfile(readme_path):
        return

    with open(readme_path, 'r', encoding='utf-8') as f:
        content = f.read()

    # Find the checklist section
    header_pattern = re.compile(r'##\s*Solved\s*Problems\s*Checklist')
    header_match = header_pattern.search(content)
    if not header_match:
        return

    checklist_start = header_match.end()
    
    # Extract everything after the header, split into lines
    lines = content[checklist_start:].split('\n')
    
    checklist_lines = []
    after_checklist_lines = []
    in_checklist = True
    
    for line in lines:
        if in_checklist:
            if line.strip().startswith('#'):
                in_checklist = False
                after_checklist_lines.append(line)
            else:
                checklist_lines.append(line)
        else:
            after_checklist_lines.append(line)

    # List all code files in the topic folder
    code_files = {}
    for file in os.listdir(dir_path):
        ext = os.path.splitext(file)[1]
        if ext in CODE_EXTENSIONS and file != 'README.md':
            code_files[file] = parse_file_header(os.path.join(dir_path, file))

    updated_checklist_lines = []
    matched_files = set()
    
    # Parse existing checklist lines
    for line in checklist_lines:
        striped = line.strip()
        if not striped.startswith('- ['):
            updated_checklist_lines.append(line)
            continue
            
        # Check if this checklist line mentions an existing file
        found_file = None
        for filename in code_files:
            if filename in line:
                found_file = filename
                break
                
        # If not, try matching by the problem title (exact match to avoid false positive substring matches)
        if not found_file:
            for filename, (prob_name, _) in code_files.items():
                line_title = line.strip()
                # Remove checkbox prefix e.g., "- [ ] " or "- [x] "
                line_title = re.sub(r'^-\s*\[[ x]\]\s*', '', line_title)
                # Remove link markdown if present e.g., "[Title](./file)" -> "Title"
                line_title = re.sub(r'^\[(.*?)\]\(.*?\)', r'\1', line_title)
                # Split by pipe and take the title portion
                line_title = line_title.split('|')[0].strip()
                
                if prob_name.lower() == line_title.lower():
                    found_file = filename
                    break

        
        if found_file:
            matched_files.add(found_file)
            prob_name, difficulty = code_files[found_file]
            new_line = f"- [x] [{prob_name}](./{found_file}) | **{difficulty}**"
            leading_whitespace = line[:len(line) - len(line.lstrip())]
            updated_checklist_lines.append(leading_whitespace + new_line)
        else:
            # Handle placeholder lines like "- [ ] Next Array Problem"
            if "Next " in line and " Problem" in line and len(matched_files) < len(code_files):
                unmatched = [f for f in code_files if f not in matched_files]
                if unmatched:
                    next_file = unmatched[0]
                    matched_files.add(next_file)
                    prob_name, difficulty = code_files[next_file]
                    leading_whitespace = line[:len(line) - len(line.lstrip())]
                    new_line = f"- [x] [{prob_name}](./{next_file}) | **{difficulty}**"
                    updated_checklist_lines.append(leading_whitespace + new_line)
            else:
                updated_checklist_lines.append(line)

    # Append any remaining unmatched files to the checklist
    unmatched_files = [f for f in code_files if f not in matched_files]
    if unmatched_files:
        insert_idx = len(updated_checklist_lines)
        while insert_idx > 0 and updated_checklist_lines[insert_idx - 1].strip() == "":
            insert_idx -= 1
            
        for file in unmatched_files:
            prob_name, difficulty = code_files[file]
            new_line = f"- [x] [{prob_name}](./{file}) | **{difficulty}**"
            updated_checklist_lines.insert(insert_idx, new_line)
            insert_idx += 1

    # Reconstruct topic README
    new_checklist_str = '\n'.join(updated_checklist_lines)
    after_checklist_str = '\n'.join(after_checklist_lines)
    
    new_content = content[:checklist_start] + new_checklist_str
    if after_checklist_str:
        new_content += '\n' + after_checklist_str
        
    with open(readme_path, 'w', encoding='utf-8') as f:
        f.write(new_content)

def count_solved_problems(dir_name):
    dir_path = os.path.join(REPO_DIR, dir_name)
    if not os.path.isdir(dir_path):
        return 0
    count = 0
    for file in os.listdir(dir_path):
        ext = os.path.splitext(file)[1]
        if ext in CODE_EXTENSIONS and file != 'README.md':
            count += 1
    return count

def update_readme():
    if not os.path.isfile(README_PATH):
        print(f"Error: README.md not found at {README_PATH}")
        return

    with open(README_PATH, 'r', encoding='utf-8') as f:
        content = f.read()

    # Regex for tracking table rows
    row_pattern = re.compile(
        r'^\|\s*(?P<num>\d+)\s*\|\s*\*\*(?P<topic>.*?)\*\*\s*\|\s*\[`/?(?P<dir>.*?)`\]\((?P<link>.*?)\)\s*\|\s*(?P<solved>\d+)\s*\|\s*(?P<target>\d+)\s*\|\s*(?P<status>.*?)\s*\|',
        re.MULTILINE
    )

    matches = list(row_pattern.finditer(content))
    if not matches:
        print("No tracker rows found in README.md.")
        return

    # Count solved for each directory and reconstruct rows
    total_solved = 0
    total_target = 0
    new_content = content
    
    # We will replace rows in reverse order to keep indices correct
    for match in reversed(matches):
        num = match.group('num')
        topic = match.group('topic')
        directory = match.group('dir').strip('/')
        link = match.group('link')
        target = int(match.group('target'))
        
        # Update individual topic README checklists first
        update_topic_readme(directory)
        
        solved = count_solved_problems(directory)
        total_solved += solved
        total_target += target
        
        if solved == 0:
            status = "⚪ Planned"
        elif solved < target:
            status = "🟡 In Progress"
        else:
            status = "🟢 Completed"
            
        new_row = f"| {num} | **{topic}** | [`/{directory}`]({link}) | {solved} | {target} | {status} |"
        start, end = match.span()
        new_content = new_content[:start] + new_row + new_content[end:]

    # Calculate total progress percentage
    percentage = (total_solved / 300.0) * 100
    percentage = min(percentage, 100.0)
    filled_blocks = int(percentage / 5)
    bar = "■" * filled_blocks + "░" * (20 - filled_blocks)
    
    progress_bar_regex = re.compile(
        r'Progress:\s*\[[■░]+\]\s*[\d\.]+% Completed\s*\(\s*\d+\s*/\s*300\+\s*Problems Solved\)'
    )
    new_progress_bar = f"Progress: [{bar}] {percentage:.1f}% Completed ({total_solved} / 300+ Problems Solved)"
    new_content = progress_bar_regex.sub(new_progress_bar, new_content)
    
    # Update Metrics Table
    solved_regex = re.compile(
        r'(\|\s*\*\*Total Problems Solved\*\*\s*\|\s*\*\*)\d+(\*\* / 300\+\s*\|)'
    )
    new_content = solved_regex.sub(rf'\g<1>{total_solved}\2', new_content)
    
    cpp_regex = re.compile(
        r'(\|\s*\*\*C\+\+ Implementations\*\*\s*\|\s*\*\*)\d+(\*\*\s*\|)'
    )
    new_content = cpp_regex.sub(rf'\g<1>{total_solved}\2', new_content)

    with open(README_PATH, 'w', encoding='utf-8') as f:
        f.write(new_content)
        
    print(f"README.md and Topic READMEs updated successfully! Total Solved: {total_solved}")

if __name__ == '__main__':
    update_readme()
