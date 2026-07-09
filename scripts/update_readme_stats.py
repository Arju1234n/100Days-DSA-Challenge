import os
import re

# Directory of the repo
REPO_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
README_PATH = os.path.join(REPO_DIR, 'README.md')

CODE_EXTENSIONS = {'.cpp', '.py', '.java', '.go', '.rs', '.js', '.ts', '.c', '.h'}

def count_solved_problems(dir_name):
    dir_path = os.path.join(REPO_DIR, dir_name)
    if not os.path.isdir(dir_path):
        return 0
    count = 0
    for file in os.listdir(dir_path):
        ext = os.path.splitext(file)[1]
        if ext in CODE_EXTENSIONS:
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
        
    print(f"README.md updated successfully! Total Solved: {total_solved}")

if __name__ == '__main__':
    update_readme()
