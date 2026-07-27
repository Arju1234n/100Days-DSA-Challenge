/*
Problem Name: Find Largest Value in Each Tree Row
Platform: LeetCode
Difficulty: Medium

Approach: Breadth-First Search (BFS) using a queue to traverse the tree level by level and keeping track of the maximum value in each level.

Time Complexity: O(n)
Space Complexity: O(n)

Pattern: BFS / Queue
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cassert>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int maxi = INT_MIN;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                maxi = max(maxi, curr->val);

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            ans.push_back(maxi);
        }

        return ans;
    }
};

// Helper function to delete tree and free memory
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution sol;

    // Test Case 1: Example tree
    //      1
    //     / \
    //    3   2
    //   / \   \
    //  5   3   9
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);
    root1->left->right = new TreeNode(3);
    root1->right->right = new TreeNode(9);

    vector<int> expected1 = {1, 3, 9};
    assert(sol.largestValues(root1) == expected1);
    deleteTree(root1);

    // Test Case 2: Example tree
    //     1
    //    / \
    //   2   3
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    vector<int> expected2 = {1, 3};
    assert(sol.largestValues(root2) == expected2);
    deleteTree(root2);

    // Test Case 3: Empty tree
    assert(sol.largestValues(nullptr).empty());

    // Test Case 4: Single node
    TreeNode* root4 = new TreeNode(1);
    vector<int> expected4 = {1};
    assert(sol.largestValues(root4) == expected4);
    deleteTree(root4);

    cout << "Find Largest Value in Each Tree Row C++: All tests passed! 🎉" << endl;
    return 0;
}
