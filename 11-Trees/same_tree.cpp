/*
Problem Name: Same Tree
Platform: LeetCode
Difficulty: Easy

Approach: Recursive Pre-Order Traversal (DFS).
- If both trees are null, they are same (return true).
- If only one tree is null, they are not same (return false).
- If the node values differ, they are not same (return false).
- Recursively check left subtrees and right subtrees.

Time Complexity: O(n) where n is the number of nodes in the smaller tree
Space Complexity: O(h) where h is the height of the tree, representing recursive call stack space

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;

        if (p == nullptr || q == nullptr)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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

    // Test Case 1: Same trees
    //      1          1
    //     / \        / \
    //    2   3      2   3
    TreeNode* p1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    assert(sol.isSameTree(p1, q1) == true);
    deleteTree(p1);
    deleteTree(q1);

    // Test Case 2: Different structures
    //      1          1
    //     /            \
    //    2              2
    TreeNode* p2 = new TreeNode(1, new TreeNode(2), nullptr);
    TreeNode* q2 = new TreeNode(1, nullptr, new TreeNode(2));
    assert(sol.isSameTree(p2, q2) == false);
    deleteTree(p2);
    deleteTree(q2);

    // Test Case 3: Different values
    //      1          1
    //     / \        / \
    //    2   1      1   2
    TreeNode* p3 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    TreeNode* q3 = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    assert(sol.isSameTree(p3, q3) == false);
    deleteTree(p3);
    deleteTree(q3);

    cout << "Same Tree C++: All tests passed! 🎉" << endl;
    return 0;
}
