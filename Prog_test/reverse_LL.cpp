//Write a program to reverse a singly linked list.


#include <iostream>

using namespace std;

// Definition of a singly linked list node
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;        // Move prev one step ahead
        current = next;        // Move current one step ahead
    }
    return prev; // New head of the reversed list
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to insert a node at the end of the list
void append(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Node* head = nullptr;
    system("cls");
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    
    cout << "Original List: ";
    printList(head);
    
    // Reverse the linked list
    head = reverseList(head);
    
    cout << "Reversed List: ";
    printList(head);
    
    return 0;
}
