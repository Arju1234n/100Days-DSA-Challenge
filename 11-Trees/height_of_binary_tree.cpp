/*
Problem Name: Height of Binary Tree (Maximum Depth of Binary Tree)
Platform: GeeksforGeeks / LeetCode
Difficulty: Easy

Approach: Depth-First Search (DFS) / Recursion.
Height is defined here as the number of edges on the longest path from the root to a leaf (returns -1 for NULL root, 0 for a single node).
For node-count based height/depth (returns 0 for NULL root), the base case would return 0.

Time Complexity: O(n)
Space Complexity: O(h) where h is the tree height.

Pattern: DFS / Recursion
*/

#include <iostream>
#include <algorithm>
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
    int height(Node* root) {
        if (root == nullptr)
            return -1;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
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
    // Height (edges) is 2 (path: 1 -> 2 -> 4 or 1 -> 2 -> 5)
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    assert(sol.height(root1) == 2);
    deleteTree(root1);

    // Test Case 2: Empty tree (height should be -1)
    assert(sol.height(nullptr) == -1);

    // Test Case 3: Single node (height should be 0)
    Node* root3 = new Node(10);
    assert(sol.height(root3) == 0);
    deleteTree(root3);

    cout << "Height of Binary Tree C++: All tests passed! 🎉" << endl;
    return 0;
}
