/*
Problem Name: Given a sorted linked list and a value to insert, insert the node in sorted order
Platform: GeeksForGeeks
Difficulty: Easy

Approach:
- Create a new node `newNode` with data `key`.
- If the list is empty (`head == NULL`), return `newNode`.
- If `key <= head->data`, insert `newNode` at the beginning and return `newNode`.
- Otherwise, traverse the linked list using a pointer `temp` while `temp->next != NULL` and `temp->next->data < key`.
- Insert `newNode` after `temp` (`newNode->next = temp->next; temp->next = newNode;`).
- Return `head`.

Time Complexity: O(n) worst case
Space Complexity: O(1) auxiliary space

Pattern: Linked List Traversal / Pointer Manipulation
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
    Node* sortedInsert(Node* head, int key) {

        Node* newNode = new Node(key);

        // Empty list
        if(head == NULL)
            return newNode;

        // Insert at beginning
        if(key <= head->data) {
            newNode->next = head;
            return newNode;
        }

        Node* temp = head;

        // Find correct position
        while(temp->next != NULL &&
              temp->next->data < key) {

            temp = temp->next;
        }

        // Insert node
        newNode->next = temp->next;
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

    // Test Case 1: Insert into middle of list
    Node* head1 = createList({2, 5, 7, 10, 15});
    head1 = sol.sortedInsert(head1, 9);
    assert(listToVector(head1) == std::vector<int>({2, 5, 7, 9, 10, 15}));
    freeList(head1);

    // Test Case 2: Insert at beginning (smaller than head)
    Node* head2 = createList({2, 5, 7});
    head2 = sol.sortedInsert(head2, 1);
    assert(listToVector(head2) == std::vector<int>({1, 2, 5, 7}));
    freeList(head2);

    // Test Case 3: Insert at end (larger than all elements)
    Node* head3 = createList({2, 5, 7});
    head3 = sol.sortedInsert(head3, 10);
    assert(listToVector(head3) == std::vector<int>({2, 5, 7, 10}));
    freeList(head3);

    // Test Case 4: Insert into empty list
    Node* head4 = nullptr;
    head4 = sol.sortedInsert(head4, 5);
    assert(listToVector(head4) == std::vector<int>({5}));
    freeList(head4);

    // Test Case 5: Insert duplicate value
    Node* head5 = createList({2, 5, 7});
    head5 = sol.sortedInsert(head5, 5);
    assert(listToVector(head5) == std::vector<int>({2, 5, 5, 7}));
    freeList(head5);

    std::cout << "Insert in a Sorted List: All tests passed! 🎉" << std::endl;
    return 0;
}
