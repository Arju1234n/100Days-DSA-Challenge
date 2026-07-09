import os
import subprocess
from datetime import datetime, timedelta
import random

REPO_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CONTRIB_FILE = os.path.join(REPO_DIR, 'scripts', 'contributions.txt')

def run_cmd(args, env=None):
    current_env = os.environ.copy()
    if env:
        current_env.update(env)
    current_env['PATH'] = current_env.get('PATH', '') + ':/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin'
    
    result = subprocess.run(args, cwd=REPO_DIR, capture_output=True, text=True, env=current_env)
    if result.returncode != 0:
        raise Exception(f"Command {' '.join(args)} failed:\nSTDOUT: {result.stdout}\nSTDERR: {result.stderr}")
    return result.stdout.strip()

def backdate_contributions(start_days_ago=30, end_days_ago=1, commits_per_day=50):
    os.makedirs(os.path.dirname(CONTRIB_FILE), exist_ok=True)
    
    print(f"Generating backdated contributions from {start_days_ago} to {end_days_ago} days ago...")
    
    # Try to pull latest changes to avoid conflicts
    try:
        run_cmd(['git', 'pull', 'origin', 'main', '--rebase', '--autostash'])
    except Exception as e:
        print(f"Warning: git pull failed: {e}. Attempting to proceed anyway.")

    total_commits = 0
    now = datetime.now()
    
    # Iterate backwards from start_days_ago down to end_days_ago
    for days_ago in range(start_days_ago, end_days_ago - 1, -1):
        target_date = now - timedelta(days=days_ago)
        
        # Simulate active days (e.g. 90% chance to commit on any given day for a natural look)
        if random.random() > 0.90:
            continue
            
        print(f"Backdating commits for {target_date.strftime('%Y-%m-%d')}...")
        
        for i in range(1, commits_per_day + 1):
            # Generate a random time during the day for the commit
            hour = random.randint(9, 21)
            minute = random.randint(0, 59)
            second = random.randint(0, 59)
            commit_time = target_date.replace(hour=hour, minute=minute, second=second)
            date_str = commit_time.isoformat()
            
            content = f"Backdated contribution {i}/{commits_per_day} for {date_str}\n"
            with open(CONTRIB_FILE, 'a') as f:
                f.write(content)
                
            run_cmd(['git', 'add', CONTRIB_FILE])
            commit_msg = f"chore: backdated contribution {i} of {commits_per_day} [{commit_time.strftime('%Y-%m-%d')}]"
            
            # Run git commit with backdated env variables
            env_override = {
                'GIT_AUTHOR_DATE': date_str,
                'GIT_COMMITTER_DATE': date_str
            }
            run_cmd(['git', 'commit', '-m', commit_msg], env=env_override)
            total_commits += 1

    print(f"Created {total_commits} backdated commits locally. Pushing to origin...")
    try:
        run_cmd(['git', 'push', 'origin', 'main'])
        print("Successfully pushed all backdated contributions!")
    except Exception as e:
        print(f"Error during git push: {e}")

if __name__ == '__main__':
    # Default: Backdate from 30 days ago to 1 day ago, making 50 commits per active day
    backdate_contributions(start_days_ago=30, end_days_ago=1, commits_per_day=50)
