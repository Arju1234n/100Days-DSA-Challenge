/*
Problem Name: Count Non-Leaf Nodes in Binary Tree
Platform: GeeksforGeeks
Difficulty: Easy

Optimal Approach: Depth-First Search (DFS) / Recursion. If node is null or a leaf, return 0. Otherwise, recursively sum the non-leaf nodes in the left and right subtrees and add 1 for the current non-leaf node.

Time Complexity: O(n)
Space Complexity: O(h) where h is the tree height.

Pattern: DFS / Recursion
*/

#include <iostream>
#include <cassert>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        // Base Case
        if (root == nullptr)
            return 0;

        // Leaf Node
        if (root->left == nullptr && root->right == nullptr)
            return 0;

        // Current node is Non-Leaf
        return countNonLeafNodes(root->left)
             + countNonLeafNodes(root->right)
             + 1;
    }
};

// Helper function to delete tree and free memory
void deleteTree(Node* root) {
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
    // Non-leaf nodes are 1 and 2 (total 2)
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    assert(sol.countNonLeafNodes(root1) == 2);
    deleteTree(root1);

    // Test Case 2: Empty tree
    assert(sol.countNonLeafNodes(nullptr) == 0);

    // Test Case 3: Single node (which is a leaf)
    Node* root3 = new Node(10);
    assert(sol.countNonLeafNodes(root3) == 0);
    deleteTree(root3);

    cout << "Count Non-Leaf Nodes C++: All tests passed! 🎉" << endl;
    return 0;
}
