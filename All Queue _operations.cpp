#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <functional>
using namespace std;

// ======================================
// 1. Array-Based Circular Queue
// ======================================
#define MAX 5

class CircularQueue {
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() : front(-1), rear(-1) {}

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Circular Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue is empty\n";
            return -1;
        }
        int res = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
        return res;
    }

    int getFront() {
        return isEmpty() ? -1 : arr[front];
    }

    int getRear() {
        return isEmpty() ? -1 : arr[rear];
    }
};

// ======================================
// 2. Linked List Based Queue
// ======================================
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class LinkedQueue {
    Node *front, *rear;
public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(int x) {
        Node* temp = new Node(x);
        if (!rear) front = rear = temp;
        else {
            rear->next = temp;
            rear = temp;
        }
    }

    int dequeue() {
        if (!front) {
            cout << "Linked Queue is empty\n";
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        return val;
    }
};

// ======================================
// 3. Queue Using Two Stacks
// ======================================
class QueueWithStacks {
    stack<int> s1, s2;

    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s2.empty()) transfer();
        if (s2.empty()) {
            cout << "QueueWithStacks is empty\n";
            return -1;
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
};

// ======================================
// 4. Priority Queue (Max and Min Heap)
// ======================================
void priorityQueueDemo() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    maxHeap.push(10); maxHeap.push(30); maxHeap.push(20);
    minHeap.push(10); minHeap.push(30); minHeap.push(20);

    cout << "\nMaxHeap Top: " << maxHeap.top() << endl;
    cout << "MinHeap Top: " << minHeap.top() << endl;
}

// ======================================
// 5. Deque Demo
// ======================================
void dequeDemo() {
    deque<int> dq;
    dq.push_front(10);
    dq.push_back(20);
    dq.push_front(5);
    cout << "\nDeque Front: " << dq.front() << ", Back: " << dq.back() << endl;
    dq.pop_back();
    dq.pop_front();
}

// ======================================
// 6. STL Queue Demo
// ======================================
void stlQueueDemo() {
    queue<int> q;
    q.push(1); q.push(2); q.push(3);
    cout << "\nSTL Queue Front: " << q.front() << ", Back: " << q.back() << endl;
    q.pop();
}

// ======================================
// MAIN FUNCTION
// ======================================
int main() {
    cout << "== Circular Queue ==\n";
    CircularQueue cq;
    cq.enqueue(1); cq.enqueue(2); cq.enqueue(3); cq.enqueue(4); cq.enqueue(5);
    cq.enqueue(6);
    cout << "Front: " << cq.getFront() << ", Rear: " << cq.getRear() << endl;
    cq.dequeue(); cq.enqueue(6);

    cout << "Dequeuing from Circular Queue: ";
    while (!cq.isEmpty()) cout << cq.dequeue() << " ";
    cout << "\n";

    cout << "\n== Linked List Queue ==\n";
    LinkedQueue lq;
    lq.enqueue(10); lq.enqueue(20); lq.enqueue(30);
    cout << "Dequeuing from Linked Queue: ";
    cout << lq.dequeue() << " " << lq.dequeue() << " " << lq.dequeue() << "\n";

    cout << "\n== Queue Using Two Stacks ==\n";
    QueueWithStacks qws;
    qws.enqueue(100); qws.enqueue(200); qws.enqueue(300);
    cout << "Dequeuing from Stack Queue: ";
    cout << qws.dequeue() << " " << qws.dequeue() << " " << qws.dequeue() << "\n";

    cout << "\n== Priority Queue Demo ==\n";
    priorityQueueDemo();

    cout << "\n== Deque Demo ==\n";
    dequeDemo();

    cout << "\n== STL Queue Demo ==\n";
    stlQueueDemo();

    return 0;
}
