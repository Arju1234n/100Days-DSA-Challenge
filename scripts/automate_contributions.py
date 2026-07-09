import os
import subprocess
from datetime import datetime

# Determine repository root
REPO_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CONTRIB_FILE = os.path.join(REPO_DIR, 'scripts', 'contributions.txt')

def run_cmd(args):
    # Pass existing environment to subprocess
    env = os.environ.copy()
    # Add common PATH entries just in case
    env['PATH'] = env.get('PATH', '') + ':/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin'
    
    result = subprocess.run(args, cwd=REPO_DIR, capture_output=True, text=True, env=env)
    if result.returncode != 0:
        raise Exception(f"Command {' '.join(args)} failed:\nSTDOUT: {result.stdout}\nSTDERR: {result.stderr}")
    return result.stdout.strip()

def make_contributions(count=50):
    os.makedirs(os.path.dirname(CONTRIB_FILE), exist_ok=True)
    
    print(f"[{datetime.now().isoformat()}] Starting {count} contributions...")
    
    # Try to pull latest changes to avoid conflicts, using autostash for unstaged files
    try:
        run_cmd(['git', 'pull', 'origin', 'main', '--rebase', '--autostash'])
    except Exception as e:
        print(f"Warning: git pull failed: {e}. Attempting to proceed anyway.")
        
    for i in range(1, count + 1):
        timestamp = datetime.now().isoformat()
        content = f"Contribution {i}/{count} on {timestamp}\n"
        
        with open(CONTRIB_FILE, 'a') as f:
            f.write(content)
            
        run_cmd(['git', 'add', CONTRIB_FILE])
        commit_msg = f"chore: daily contribution {i} of {count} [{datetime.now().strftime('%Y-%m-%d')}]"
        run_cmd(['git', 'commit', '-m', commit_msg])
        
    print(f"[{datetime.now().isoformat()}] Created {count} commits locally. Pushing to origin...")
    try:
        run_cmd(['git', 'push', 'origin', 'main'])
        print(f"[{datetime.now().isoformat()}] Successfully pushed all contributions!")
    except Exception as e:
        print(f"Error during git push: {e}")
        print("Tip: If running under cron, verify your ssh-agent or credential helper configuration.")

if __name__ == '__main__':
    make_contributions(50)
