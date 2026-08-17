/*
Problem Name: Linked List Insertion At End
Platform: GeeksForGeeks
Difficulty: Easy

Approach: Allocate a new node with data x. If the list is empty (head is NULL), return the new node as the head. Otherwise, traverse to the last node (where temp->next == NULL) and point temp->next to the new node.

Time Complexity: O(n) worst case to reach the end of the list
Space Complexity: O(1) auxiliary space

Pattern: Linked List Traversal / Pointer Manipulation
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
    Node *insertAtEnd(Node *head, int x) {
        Node* newNode = new Node(x);

        if(head == NULL) {
            return newNode;
        }

        Node* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;

        return head;
    }
};

// Helper function to convert linked list to vector for assertion
std::vector<int> listToVector(Node* head) {
    std::vector<int> res;
    while (head != NULL) {
        res.push_back(head->data);
        head = head->next;
    }
    return res;
}

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

    // Test Case 1: Insert into non-empty list
    Node* head1 = createList({1, 2, 3, 4});
    head1 = sol.insertAtEnd(head1, 5);
    assert(listToVector(head1) == std::vector<int>({1, 2, 3, 4, 5}));
    freeList(head1);

    // Test Case 2: Insert into empty list
    Node* head2 = createList({});
    head2 = sol.insertAtEnd(head2, 10);
    assert(listToVector(head2) == std::vector<int>({10}));
    freeList(head2);

    // Test Case 3: Sequential insertions
    Node* head3 = nullptr;
    head3 = sol.insertAtEnd(head3, 1);
    head3 = sol.insertAtEnd(head3, 2);
    head3 = sol.insertAtEnd(head3, 3);
    assert(listToVector(head3) == std::vector<int>({1, 2, 3}));
    freeList(head3);

    std::cout << "Linked List Insertion At End: All tests passed! 🎉" << std::endl;
    return 0;
}
