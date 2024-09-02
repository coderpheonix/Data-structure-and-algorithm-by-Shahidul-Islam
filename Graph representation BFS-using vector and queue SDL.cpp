#include<iostream>  // Required for input-output stream
#include<vector>    // Required for using the vector container
#include<queue>     // Required for using the queue container

using namespace std;

// Function to perform BFS traversal starting from a given vertex
void BFS(int startVertex, vector<vector<int>> & adjList)
{
    int numVertices = adjList.size();             // Number of vertices in the graph
    vector<bool> visited(numVertices, false);     // A boolean vector to keep track of visited vertices
    queue<int> q;                                 // Queue to manage the BFS traversal order

    visited[startVertex] = true;  // Mark the start vertex as visited
    q.push(startVertex);          // Enqueue the start vertex

    cout << "BFS Traversal: ";    // Output for BFS traversal

    // Continue the traversal until all vertices in the queue are processed
    while (!q.empty())
    {
        int vertext = q.front();  // Get the vertex at the front of the queue
        q.pop();                  // Remove it from the queue
        cout << vertext << " ";   // Print the current vertex

        // Iterate over all adjacent vertices of the current vertex
        for(int adjacent: adjList[vertext])
        {
            // If the adjacent vertex has not been visited, mark it as visited and enqueue it
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                q.push(adjacent);
            }
        }
    }

    cout << endl;  // Move to the next line after traversal
}

int main ()
{
    int numVertices = 6;  // Total number of vertices in the graph

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(numVertices);

    // Adding edges to the graph (undirected graph)
    adjList[0].push_back(1);  // Edge from vertex 0 to vertex 1
    adjList[0].push_back(2);  // Edge from vertex 0 to vertex 2
    adjList[1].push_back(0);  // Edge from vertex 1 to vertex 0
    adjList[1].push_back(3);  // Edge from vertex 1 to vertex 3
    adjList[2].push_back(0);  // Edge from vertex 2 to vertex 0
    adjList[2].push_back(4);  // Edge from vertex 2 to vertex 4
    adjList[3].push_back(1);  // Edge from vertex 3 to vertex 1
    adjList[3].push_back(5);  // Edge from vertex 3 to vertex 5
    adjList[4].push_back(4);  // Edge from vertex 4 to vertex 4 (self-loop)
    adjList[5].push_back(3);  // Edge from vertex 5 to vertex 3

    // Perform BFS starting from vertex 0
    BFS(0, adjList);

    return 0;
}
