/*
Problem Name: Count Complete Tree Nodes
Platform: LeetCode
Difficulty: Easy

Approach 1: Simple recursive traversal. Time: O(n), Space: O(h) where h is the tree height.
Optimal Approach for Complete Binary Tree: Check if the left height equals the right height. If so, it's a perfect binary tree, and nodes = 2^h - 1. Otherwise, recursively solve for left and right subtrees. Time: O(log^2 n), Space: O(log n).
(Below code implements the user's recursive traversal approach).

Time Complexity: O(n)
Space Complexity: O(h)

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
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
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
    //   / \  /
    //  4   5 6
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);

    assert(sol.countNodes(root1) == 6);
    deleteTree(root1);

    // Test Case 2: Empty tree
    assert(sol.countNodes(nullptr) == 0);

    // Test Case 3: Single node
    TreeNode* root3 = new TreeNode(1);
    assert(sol.countNodes(root3) == 1);
    deleteTree(root3);

    cout << "Count Complete Tree Nodes C++: All tests passed! 🎉" << endl;
    return 0;
}
