/*
Problem Name: Minimum Depth of Binary Tree
Platform: LeetCode
Difficulty: Easy

Approach: Recursive Depth-First Search (DFS).
- If root is null, minimum depth is 0.
- If left child is null, recurse on right child.
- If right child is null, recurse on left child.
- If both children exist, return 1 + min of left and right child depths.

Time Complexity: O(n) where n is the number of nodes in the tree
Space Complexity: O(h) where h is the height of the tree, representing recursive call stack space

Pattern: DFS / Recursion
*/

#include <iostream>
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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr)
            return minDepth(root->right) + 1;

        if (root->right == nullptr)
            return minDepth(root->left) + 1;

        return min(minDepth(root->left), minDepth(root->right)) + 1;
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

    assert(sol.minDepth(root1) == 2);
    deleteTree(root1);

    // Test Case 2: Skewed tree
    //   2
    //    \
    //     3
    //      \
    //       4
    //        \
    //         5
    TreeNode* root2 = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(4);
    root2->right->right->right = new TreeNode(5);

    assert(sol.minDepth(root2) == 4);
    deleteTree(root2);

    // Test Case 3: Empty tree
    assert(sol.minDepth(nullptr) == 0);

    // Test Case 4: Single node
    TreeNode* root4 = new TreeNode(1);
    assert(sol.minDepth(root4) == 1);
    deleteTree(root4);

    cout << "Minimum Depth of Binary Tree C++: All tests passed! 🎉" << endl;
    return 0;
}
