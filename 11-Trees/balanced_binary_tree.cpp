/*
Problem Name: Balanced Binary Tree
Platform: LeetCode
Difficulty: Easy

Approach: Post-order DFS traversal. For each node, recursively check the height of the left and right subtrees.
- If a subtree is unbalanced (height returned is -1), return -1.
- If the difference in height between left and right subtree exceeds 1, return -1.
- Otherwise, return the height of the tree rooted at the current node: max(left, right) + 1.

Time Complexity: O(n) where n is the number of nodes in the tree, as we visit each node once.
Space Complexity: O(h) where h is the height of the tree, representing the recursion stack.

Pattern: DFS / Tree Recursion / Post-order Traversal
*/

#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>

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
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = height(root->left);
        if (left == -1)
            return -1;

        int right = height(root->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution sol;

    // Test Case 1: Balanced Tree
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    assert(sol.isBalanced(root1) == true);
    deleteTree(root1);

    // Test Case 2: Unbalanced Tree
    //         1
    //        / \
    //       2   2
    //      / \
    //     3   3
    //    / \
    //   4   4
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3, new TreeNode(4), new TreeNode(4));
    root2->left->right = new TreeNode(3);
    assert(sol.isBalanced(root2) == false);
    deleteTree(root2);

    // Test Case 3: Empty Tree
    assert(sol.isBalanced(nullptr) == true);

    cout << "Balanced Binary Tree C++: All tests passed! 🎉" << endl;
    return 0;
}
