/*
Problem Name: Binary Tree Level Order Traversal
Platform: LeetCode
Difficulty: Medium

Optimal Approach: Breadth-First Search (BFS) using a queue to traverse the tree level by level.

Time Complexity: O(n)
Space Complexity: O(n)

Pattern: BFS / Queue
*/

#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            ans.push_back(level);
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

    // Test Case 1: Example tree:
    //      3
    //     / \
    //    9  20
    //      /  \
    //     15   7
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    vector<vector<int>> expected1 = {
        {3},
        {9, 20},
        {15, 7}
    };
    assert(sol.levelOrder(root1) == expected1);
    deleteTree(root1);

    // Test Case 2: Empty tree
    assert(sol.levelOrder(nullptr).empty());

    // Test Case 3: Single node
    TreeNode* root3 = new TreeNode(1);
    vector<vector<int>> expected3 = {{1}};
    assert(sol.levelOrder(root3) == expected3);
    deleteTree(root3);

    cout << "Binary Tree Level Order Traversal C++: All tests passed! 🎉" << endl;
    return 0;
}
