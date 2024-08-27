
#include <iostream>  // Include the iostream library for input/output operations
#include <list>      // Include the list library to use the list container
#include <queue>     // Include the queue library to use the queue container

using namespace std;  // Use the standard namespace to avoid using 'std::' before every standard library object

// Class to represent a graph
class Graph {
    int V;             // Number of vertices in the graph
    list<int>* adj;    // Pointer to an array of adjacency lists

public:
    Graph(int V);      // Constructor to initialize the graph with V vertices
    void addEdge(int v, int w); // Function to add an edge between vertex v and vertex w
    void BFS(int s);   // Function to perform Breadth-First Search starting from vertex s
};

// Constructor to initialize the graph with V vertices
Graph::Graph(int V) {
    this->V = V;               // Set the number of vertices
    adj = new list<int>[V];    // Create an array of lists for the adjacency list
}

// Function to add an edge between vertex v and vertex w
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add vertex w to vertex v's adjacency list
    adj[w].push_back(v); // Add vertex v to vertex w's adjacency list (for undirected graph)
}

// Function to perform Breadth-First Search starting from vertex s
void Graph::BFS(int s) {
    bool* visited = new bool[V];   // Create a boolean array to mark visited vertices
    for (int i = 0; i < V; i++)    // Initialize all vertices as not visited
        visited[i] = false;

    queue<int> queue;  // Create a queue for BFS

    visited[s] = true; // Mark the starting vertex as visited
    queue.push(s);     // Enqueue the starting vertex

    while (!queue.empty()) {  // Loop until the queue is empty
        s = queue.front();    // Get the front vertex from the queue
        cout << s << " ";     // Print the current vertex
        queue.pop();          // Dequeue the front vertex

        // Get all adjacent vertices of the dequeued vertex s
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {  // If the adjacent vertex has not been visited
                visited[*i] = true;  // Mark it as visited
                queue.push(*i);      // Enqueue the adjacent vertex
            }
        }
    }
}

int main() {
    Graph g(5);  // Create a graph with 5 vertices

    // Add edges between vertices
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Breadth First Traversal starting from vertex 0:\n";
    g.BFS(0);  // Perform BFS starting from vertex 0

    return 0;  // Return 0 to indicate successful execution
}
