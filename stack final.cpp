#include <iostream> // Include the input-output stream library
using namespace std;

#define MAX 5 // Define the maximum size of the stack

// Declare the stack and the top variable
int stack[MAX], top = -1;

// Function to check if the stack is empty
bool isEmpty() {
    // If top is -1, stack is empty
    return top == -1;
}

// Function to check if the stack is full
bool isFull() {
    // If top is equal to the last index, stack is full
    return top == MAX - 1;
}

// Function to push an element onto the stack
void push(int x) {
    // Check if the stack is full
    if (isFull()) {
        cout << "The stack is full." << endl; // Display a message if the stack is full
    } else {
        top++; // Increment the top index
        stack[top] = x; // Add the new element to the top of the stack
    }
}

// Function to pop an element from the stack
void pop() {
    // Check if the stack is empty
    if (isEmpty()) {
        cout << "The stack is empty." << endl; // Display a message if the stack is empty
    } else {
        cout << "Popped element: " << stack[top] << endl; // Display the popped element
        top--; // Decrement the top index to remove the top element
    }
}

// Function to peek the top element of the stack
int peek() {
    // Check if the stack is empty
    if (isEmpty()) {
        cout << "The stack is empty." << endl; // Display a message if the stack is empty
        return -1; // Return -1 if the stack is empty
    } else {
        return stack[top]; // Return the top element of the stack
    }
}

// Function to display the elements of the stack
void display() {
    // Check if the stack is empty
    if (isEmpty()) {
        cout << "The stack is empty." << endl; // Display a message if the stack is empty
    } else {
        cout << "Stack elements: " << endl; // Display a message indicating stack elements
        // Loop through the stack from top to bottom
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl; // Print each element of the stack
        }
    }
}

// Main function
int main() {
    push(1); // Push 1 onto the stack
    push(2); // Push 2 onto the stack
    push(3); // Push 3 onto the stack
     push(4);
    display(); // Display the stack elements
    pop(); // Pop the top element from the stack
    display(); // Display the stack elements after popping
    cout << "Top element: " << peek() << endl; // Display the top element of the stack
    return 0; // Return 0 to indicate successful execution
}

