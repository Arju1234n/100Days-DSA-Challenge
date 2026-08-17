/*
Problem Name: Check if Linked List is Circular
Platform: GeeksForGeeks
Difficulty: Easy

Approach: 
- An empty list (head == NULL) is considered circular.
- Start a pointer `temp` from `head->next`.
- Advance `temp` while it is neither NULL nor back at `head`.
- If `temp` eventually points back to `head`, the list is circular (return true).
- If `temp` becomes NULL, the list is NULL-terminated / singly linear (return false).

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space

Pattern: Linked List Traversal / Cycle Detection
*/

#include <iostream>
#include <vector>
#include <cassert>

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
  public:
    bool isCircular(Node *head) {
        if (head == nullptr)
            return true;

        Node* temp = head->next;

        while (temp != nullptr && temp != head) {
            temp = temp->next;
        }

        return (temp == head);
    }
};

// Helper function to create a linear linked list
Node* createLinearList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to create a circular linked list
Node* createCircularList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    curr->next = head; // Make circular
    return head;
}

// Helper function to free circular list memory safely
void freeCircularList(Node* head) {
    if (head == nullptr) return;
    Node* curr = head->next;
    while (curr != nullptr && curr != head) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete head;
}

// Helper function to free linear list memory safely
void freeLinearList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;

    // Test Case 1: Circular Linked List with multiple nodes
    Node* head1 = createCircularList({1, 2, 3, 4, 5});
    assert(sol.isCircular(head1) == true);
    freeCircularList(head1);

    // Test Case 2: Linear Linked List (NULL-terminated)
    Node* head2 = createLinearList({1, 2, 3, 4, 5});
    assert(sol.isCircular(head2) == false);
    freeLinearList(head2);

    // Test Case 3: Empty List
    Node* head3 = nullptr;
    assert(sol.isCircular(head3) == true);

    // Test Case 4: Single Node Circular List
    Node* head4 = new Node(10);
    head4->next = head4;
    assert(sol.isCircular(head4) == true);
    freeCircularList(head4);

    // Test Case 5: Single Node Linear List
    Node* head5 = new Node(10);
    assert(sol.isCircular(head5) == false);
    freeLinearList(head5);

    std::cout << "Check if Linked List is Circular: All tests passed! 🎉" << std::endl;
    return 0;
}
