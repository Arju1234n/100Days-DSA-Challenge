# Contribution Guidelines

Thank you for your interest in contributing to the **100Days-DSA-Challenge** repository! Contributions from the community help make this a premium open-source resource for DSA preparation.

---

## 🗺️ How to Contribute

### 1. Claim or Create an Issue
Before making any changes, please search existing issues or open a new one to discuss what you'd like to add or change.

### 2. Fork the Repository
Fork this repository to your own account and clone it locally:
```bash
git clone https://github.com/YOUR_USERNAME/100Days-DSA-Challenge.git
cd 100Days-DSA-Challenge
```

### 3. Create a Topic Branch
Use a clean branch name describing your addition:
```bash
git checkout -b feature/add-binary-search-problems
```

---

## 🛠️ Code Conventions

### File Templates

All code submissions **MUST** begin with the header template shown below.

#### C++ Template
```cpp
/*
Problem Name: [Problem Title on LeetCode]
Platform: LeetCode / GeeksForGeeks / HackerRank
Difficulty: Easy / Medium / Hard

Approach 1: [Briefly describe Brute Force / Naive approach]
Approach 2: [Briefly describe Better approach, if any]
Optimal Approach: [Briefly describe Optimal approach]

Time Complexity: O(...)
Space Complexity: O(...)

Pattern: [e.g., Sliding Window, Two Pointers, Hashing]
*/

#include <iostream>
// ... rest of the code

class Solution {
public:
    // implementation
};
```

---

## 📮 Pull Request Checklist
- [ ] Code follows the requested file template.
- [ ] Code is well-commented and easy to understand.
- [ ] You have run/tested the solution with basic assertions.
- [ ] Folder structure is respected (do not create day folders; put files directly under the correct `XX-Topic-Name` directories).
- [ ] Topic README's progress table is updated.
