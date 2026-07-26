/*
Problem Name: Sum of Binary Tree
Platform: GeeksforGeeks
Difficulty: Easy

Optimal Approach: Depth-First Search (DFS) / Recursion. Recursively sum the left child, right child, and add current node's data.

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
    int sumBT(Node* root) {
        if (root == nullptr)
            return 0;
        return sumBT(root->left) + sumBT(root->right) + root->data;
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
    //   / \  / \
    //  4   5 6  7
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    assert(sol.sumBT(root1) == 28);
    deleteTree(root1);

    // Test Case 2: Empty tree
    assert(sol.sumBT(nullptr) == 0);

    // Test Case 3: Single node
    Node* root3 = new Node(10);
    assert(sol.sumBT(root3) == 10);
    deleteTree(root3);

    cout << "Sum of Binary Tree C++: All tests passed! 🎉" << endl;
    return 0;
}
