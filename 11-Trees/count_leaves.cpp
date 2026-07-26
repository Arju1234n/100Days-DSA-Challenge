/*
Problem Name: Count Leaves in Binary Tree
Platform: GeeksforGeeks / LeetCode
Difficulty: Easy

Optimal Approach: Depth-First Search (DFS) / Recursion. If node is null, return 0. If node is a leaf (no left and right children), return 1. Otherwise, recursively sum the leaves in the left and right subtrees.

Time Complexity: O(n)
Space Complexity: O(h) where h is the tree height.

Pattern: DFS / Recursion
*/

#include <iostream>
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
    int countLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr && root->right == nullptr)
            return 1;

        return countLeaves(root->left) + countLeaves(root->right);
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
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    // Leaves are 4, 5, and 3 (total 3)
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    assert(sol.countLeaves(root1) == 3);
    deleteTree(root1);

    // Test Case 2: Empty tree
    assert(sol.countLeaves(nullptr) == 0);

    // Test Case 3: Single node
    TreeNode* root3 = new TreeNode(10);
    assert(sol.countLeaves(root3) == 1);
    deleteTree(root3);

    cout << "Count Leaves in Binary Tree C++: All tests passed! 🎉" << endl;
    return 0;
}
