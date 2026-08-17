/*
Problem Name: Print Linked List Elements
Platform: GeeksForGeeks
Difficulty: Easy

Approach: Iteratively traverse the singly linked list using a pointer, pushing node data into a vector until the pointer becomes null.

Time Complexity: O(n)
Space Complexity: O(n) auxiliary space for vector storage

Pattern: Linked List Traversal
*/

#include <iostream>
#include <vector>
#include <cassert>

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    std::vector<int> printList(Node *head) {
        std::vector<int> ans;

        while(head != NULL) {
            ans.push_back(head->data);
            head = head->next;
        }

        return ans;
    }
};

// Helper function to create linked list from vector
Node* createList(const std::vector<int>& arr) {
    if (arr.empty()) return NULL;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to free linked list memory
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;

    // Test Case 1: Standard linked list
    Node* head1 = createList({1, 2, 3, 4, 5});
    assert(sol.printList(head1) == std::vector<int>({1, 2, 3, 4, 5}));
    freeList(head1);

    // Test Case 2: Single node
    Node* head2 = createList({10});
    assert(sol.printList(head2) == std::vector<int>({10}));
    freeList(head2);

    // Test Case 3: Empty list
    Node* head3 = createList({});
    assert(sol.printList(head3) == std::vector<int>({}));
    freeList(head3);

    std::cout << "Print Linked List Elements: All tests passed! 🎉" << std::endl;
    return 0;
}
