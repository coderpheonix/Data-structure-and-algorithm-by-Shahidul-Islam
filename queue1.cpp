
#include <iostream>
#define MAX 5  // Define the maximum size of the queue

using namespace std;

class Queue {
    int arr[MAX]; // Array to store queue elements
    int front, rear; // Indices for the front and rear of the queue

public:
    // Constructor to initialize the queue
    Queue() : front(-1), rear(-1) {}

    // Function to check if the queue is full
    bool isFull()


     {
        return (rear + 1) % MAX == front;
    }

    // Function to check if the queue is empty
    bool isEmpty()


    {
        return front == -1;
    }

    // Function to add an element to the queue
    void enqueue(int x)
    {
    if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (front == -1) front = 0; // Initialize front if queue is empty
        rear = (rear + 1) % MAX; // Move rear to the next position
        arr[rear] = x; // Insert the element
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int result = arr[front]; // Store the front element to return
        if (front == rear) { // Check if the queue becomes empty after dequeue
            front = rear = -1; // Reset front and rear
        } else {
            front = (front + 1) % MAX; // Move front to the next position
        }
        return result; // Return the dequeued element
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front]; // Return the front element
    }

    // Function to get the rear element of the queue
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear]; // Return the rear element
    }
};

int main() {
    Queue q; // Create a queue instance
    q.enqueue(1); // Add elements to the queue
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);  // This will show "Queue is full"

    cout << "Front element: " << q.getFront() << endl; // Display the front element
    cout << "Rear element: " << q.getRear() << endl; // Display the rear element

    q.dequeue(); // Remove an element from the queue
    q.enqueue(6); // Add another element to the queue

    while (!q.isEmpty()) { // Print all elements until the queue is empty
        cout << q.dequeue() << " ";
    }

    return 0;
}
