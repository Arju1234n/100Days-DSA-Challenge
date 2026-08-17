/*
Problem Name: Count Nodes of Linked List
Platform: GeeksForGeeks
Difficulty: Easy

Approach: Traverse the linked list starting from head, incrementing a counter variable at each node until the pointer becomes NULL.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space

Pattern: Linked List Traversal / Counting
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
    int getCount(Node* head) {
        int count = 0;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }
};

// Helper function to create linked list from vector
Node* createList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
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
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;

    // Test Case 1: Standard linked list with 5 nodes
    Node* head1 = createList({1, 2, 3, 4, 5});
    assert(sol.getCount(head1) == 5);
    freeList(head1);

    // Test Case 2: Single node linked list
    Node* head2 = createList({100});
    assert(sol.getCount(head2) == 1);
    freeList(head2);

    // Test Case 3: Empty linked list
    Node* head3 = createList({});
    assert(sol.getCount(head3) == 0);
    freeList(head3);

    std::cout << "Count Nodes of Linked List: All tests passed! 🎉" << std::endl;
    return 0;
}
