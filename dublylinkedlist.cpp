
#include<iostream>
using namespace std;

// Creating structure
struct Node {
    int data;
    Node* next;
    Node* prev;  // New pointer for the previous node

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;  // Initialize prev to nullptr
    }
};

// Creating class
class LinkedList {
    Node* head;
    Node* tail;  // Add a tail pointer for efficient operations at the end
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    void append(int value);
    void deleteBeginning();
    void printList();
    void deleteEnd();
    void showMid();
    void insertAtPosition(int value, int position);
    void reverseList();
};

// Append function to add value at the end
void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;  // Update tail when the first node is added
        return;
    }

    tail->next = newNode;  // Link the new node after tail
    newNode->prev = tail;  // Set the new node's prev pointer to the current tail
    tail = newNode;  // Update tail to the new node
}

// Function to delete from the beginning
void LinkedList::deleteBeginning() {
    if (head == nullptr) {
        cout << "The List Is Empty" << endl;
        return;
    }

    Node* del = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;  // Update the prev pointer of the new head
    } else {
        tail = nullptr;  // If the list is empty, reset the tail pointer
    }

    delete del;
}

// Function to delete from the end
void LinkedList::deleteEnd() {
    if (tail == nullptr) {
        cout << "The List is empty" << endl;
        return;
    }

    Node* del = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;  // Update the next pointer of the new tail
    } else {
        head = nullptr;  // If the list is empty, reset the head pointer
    }

    delete del;
}

// Function to calculate the midpoint
void LinkedList::showMid() {
    Node *slow = head, *fast = head;

    if (head == nullptr) {
        cout << "The List Is Empty" << endl;
        return;
    }

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "The middle element is: " << slow->data << endl;
}

// Function to print the list
void LinkedList::printList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

// Function to insert a node at a specific position
void LinkedList::insertAtPosition(int value, int position) {
    Node* newNode = new Node(value);
    if (position == 1) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;

        if (tail == nullptr) {
            tail = newNode;  // If the list was empty, update the tail
        }
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        delete newNode;
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;  // If inserting at the end, update the tail
        }

        temp->next = newNode;
    }
}

// Function to reverse the list
void LinkedList::reverseList() {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // Move to the next node in the original list
    }

    if (temp != nullptr) {
        head = temp->prev;  // Update the head to the new first node
    }
}

// Main function to test the linked list operations
int main() {
    LinkedList list; // Create an instance of the LinkedList class

    // Append some values to the list
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(100);

    // Printing the value before deletion
    cout << "Before Deletion:" << endl;
    list.printList();

    // Delete from the beginning and print the list
    cout << "After deletion from beginning:" << endl;
    list.deleteBeginning();
    list.printList();

    // Delete from the end and print the list
    cout << "After deletion from end:" << endl;
    list.deleteEnd();
    list.printList();

    // Insert at a specific position and print the list
    cout << "After inserting 25 at position 2:" << endl;
    list.insertAtPosition(25, 2);
    list.printList();

    // Calculate the midpoint
    list.showMid();

    // Reverse the current value
    cout << "Before reversed:" << endl;
    list.printList();
    cout << "After reversed:" << endl;
    list.reverseList();
    list.printList();

    return 0;
}
