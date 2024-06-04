#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
     int V; // Number of vertices
     vector<vector<int>> adjList; // Adjacency list
     vector<vector<int>> adjMatrix; // Adjacency matrix


public:

     Graph(int V) {
          this->V = V;
          adjList.resize(V);
          adjMatrix.resize(V, vector<int>(V, 0)); // Initialize matrix with 0s
     }

     void addEdge(int u, int v, bool isDirected) {
          adjList[u].push_back(v); // Add v to u's list
          adjMatrix[u][v] = 1; // Mark the edge in the matrix

          if (!isDirected) {
               adjList[v].push_back(u); // For undirected graph, add edge both ways
               adjMatrix[v][u] = 1; // Mark the edge in the matrix both ways
          }
     }

     void printAdjList() {
          cout << "Adjacency List:" << endl;
          for (int i = 0; i < V; ++i) {
               cout << i << ": ";
               for (int j : adjList[i]) {
                    cout << j << " ";
               }
               cout << endl;
          }
     }

     void printAdjMatrix() {
          cout << "Adjacency Matrix:" << endl;
          for (int i = 0; i < V; ++i) {
               for (int j = 0; j < V; ++j) {
                    cout << adjMatrix[i][j] << " ";
               }
               cout << endl;
          }
     }
     // Code for BFS and DFS can be added here
     // Breadth First Search
     void BFS(int src) {
          vector<bool> visited(V, false); // Mark all vertices as not visited
          queue<int> q; // Create a queue for BFS
          visited[src] = true; // Mark the current node as visited
          q.push(src); // Enqueue the current node

          while (!q.empty()) {
               int u = q.front(); // Dequeue a vertex from queue and print it
               q.pop();
               cout << u << " ";
               // Get all adjacent vertices of the dequeued vertex u
               // If an adjacent vertex has not been visited, then mark it
               // visited and enqueue it
               for (int v : adjList[u]) {
                    if (!visited[v]) {
                         visited[v] = true;
                         q.push(v);
                    }
               }
          }
     }
     // Depth First Search
     void DFSUtil(int u, vector<bool>& visited) {
          visited[u] = true; // Mark the current node as visited
          cout << u << " "; // Print the current node

          // Recur for all the vertices adjacent to this vertex

          for (int v : adjList[u]) {
               if (!visited[v]) {
                    DFSUtil(v, visited);
               }
          }
     }

     void DFS(int src) {
          vector<bool> visited(V, false); // Mark all vertices as not visited
          DFSUtil(src, visited); // Call the recursive helper function
     }


};
int main() {
     int V = 4; // Number of vertices
     Graph g(V); // Create a graph with V vertices

     // Add edges
     g.addEdge(0, 1, false);  
     g.addEdge(0, 2, false);
     g.addEdge(1, 2, false);
     g.addEdge(2, 0, false);
     g.addEdge(2, 3, false);
     g.addEdge(3, 3, false);
     g.addEdge(1, 3, false);
     g.printAdjList();
     g.printAdjMatrix();
     
     cout << "BFS: ";
     g.BFS(2);
     cout << endl;

     cout << "DFS: ";
     g.DFS(2);
     cout << endl;

     return 0;
}