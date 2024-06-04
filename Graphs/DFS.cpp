#include <iostream> 
#include <vector>
#include <stack>
using namespace std;

// Function to perform Depth First Search on a graph represented using adjacency list

void DFS(vector<int> graph[], int vertices, int start)
{
    bool visited[vertices + 1];
    for (int i = 0; i <= vertices; i++)
    {
        visited[i] = false;
    }
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty())
    {
        int u = s.top();
        cout << u << " ";
        s.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            if (!visited[graph[u][i]])
            {
                s.push(graph[u][i]);
                visited[graph[u][i]] = true;
            }
        }
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    vector<int> graph[vertices + 1];
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "Enter edge (u, v): ";
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    DFS(graph, vertices, start);
    return 0;
}