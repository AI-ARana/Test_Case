// Given a linked list consists of data, next pointer and 
//also a random pointer which points to a random node of the list. 
//Give an algorithm and write a program for cloning the list. 

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int val) {
        data = val;
        next = nullptr;
        random = nullptr;
    }
};

// Function to clone the linked list
Node* cloneList(Node* head) {
    if (!head) return nullptr;

    // Step 1: Insert Cloned Nodes
    Node* current = head;
    while (current) {
        Node* temp = new Node(current->data);
        temp->next = current->next;
        current->next = temp;
        current = temp->next;
    }

    // Step 2: Copy Random Pointers
    current = head;
    while (current) {
        if (current->random) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    // Step 3: Separate the Cloned List
    Node* newHead = head->next;
    Node* original = head, *copy = newHead;
    while (original) {
        original->next = original->next->next;
        if (copy->next) {
            copy->next = copy->next->next;
        }
        original = original->next;
        copy = copy->next;
    }

    return newHead;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Data: " << temp->data << ", Random: ";
        if (temp->random)
            cout << temp->random->data;
        else
            cout << "NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Creating a sample list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Setting random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;
    system("cls");
    cout << "Original List:\n";
    printList(head);

    // Clone the list
    Node* clonedHead = cloneList(head);
    cout << "\nCloned List:\n";
    printList(clonedHead);

    return 0;
}
