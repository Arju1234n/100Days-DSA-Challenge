/*
Problem Name: Search in a Binary Search Tree
Platform: LeetCode
Difficulty: Easy

Approach: Recursive BST Search. We compare the target value with the root's value:
- If equal, we return the root node.
- If target is smaller, we search in the left subtree.
- If target is larger, we search in the right subtree.

Time Complexity: O(h) where h is the height of the tree (O(log n) on average, O(n) in worst case)
Space Complexity: O(h) due to recursion call stack

Pattern: Binary Search Tree / Recursion
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
            return nullptr;
        
        if (root->val == val) {
            return root;
        }
        
        if (val < root->val) {
            return searchBST(root->left, val);  
        }
        
        return searchBST(root->right, val);
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
    //      4
    //     / \
    //    2   7
    //   / \
    //  1   3
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);

    // Search for 2 (should return subtree rooted at 2)
    TreeNode* res1 = sol.searchBST(root1, 2);
    assert(res1 != nullptr);
    assert(res1->val == 2);
    assert(res1->left->val == 1);
    assert(res1->right->val == 3);

    // Search for 5 (should return nullptr)
    TreeNode* res2 = sol.searchBST(root1, 5);
    assert(res2 == nullptr);

    deleteTree(root1);

    // Test Case 2: Empty tree
    assert(sol.searchBST(nullptr, 1) == nullptr);

    cout << "Search in a Binary Search Tree C++: All tests passed! 🎉" << endl;
    return 0;
}
