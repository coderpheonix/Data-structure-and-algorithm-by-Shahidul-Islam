

// Functions in the LinkedList class:
// 1. void append(int value)
// 2. void deleteBeginning()
// 3. void deleteEnd()
// 4. void showMid()
// 5. void printList()
// 6. void insertAtPosition(int value, int position)
// 7.void to reverse the current value()


#include<iostream>
using namespace std;

// Creating structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Creating class
class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }
    void append(int value);
    void deleteBeginning();
    void printList();
    void deleteEnd();
    void showMid();
    void insertAtPosition(int value, int position);  // New function declaration
    void reverseList();
};

// Append function to add value at the end
void LinkedList::append(int value) {
    Node* newNode = new Node(value);
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

// Function to delete from the beginning
void LinkedList::deleteBeginning() {
    if (head == nullptr) {
        cout << "The List Is Empty";
    } else {
        Node* del = head;
        head = head->next;
        delete del;
    }
}

// Function to delete from the end
void LinkedList::deleteEnd() {
    if (head == nullptr) {
        cout << "The List is empty" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node *ptr = head, *prev = nullptr;
    while (ptr->next != nullptr) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = nullptr;
    delete ptr;
}

// Function to calculate the midpoint
void LinkedList::showMid() {
    Node *slow = head, *fast = head;

    if (head == nullptr) {
        cout << "The List Is Empty";
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
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

// New function to insert a node at a specific position
void LinkedList::insertAtPosition(int value, int position) {
    Node* newNode = new Node(value);
    if (position == 1) {
        newNode->next = head;
        head = newNode;
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
        temp->next = newNode;
    }
}

//Function to reverse the  current value

void LinkedList ::reverseList()
{
    Node* prev=nullptr;
    Node* current=head;
    Node* next=nullptr;

while (current!=nullptr)
{
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
}
head=prev;
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

    //Reverse the current value
    cout<<"Before reversed:"<<endl;
    list.printList();
    cout<<"After reversed:"<<endl;
    list.reverseList();
    list.printList();

    return 0;
}
