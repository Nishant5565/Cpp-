// * Breadth First Search (BFS) algorithm for graphs

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> graph[], int vertices, int start)
{
    bool visited[vertices + 1];
    for (int i = 0; i <= vertices; i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            if (!visited[graph[u][i]])
            {
                q.push(graph[u][i]);
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
    BFS(graph, vertices, start);
    return 0;
}

