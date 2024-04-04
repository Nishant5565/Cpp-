#include <iostream>
#include <vector>
using namespace std;

void adjmat(int vertices, int edges, bool type)
{
    cout << "Adjacency matrix graph: " << endl;
    int matrix[vertices][vertices] = {0};
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < edges; i++)
    {
        int r, c;
        cout << "Enter row number: ";
        cin >> r;
        cout << "Enter col number: ";
        cin >> c;
        matrix[r - 1][c - 1] = 1;
        if (!type)
        {
            matrix[c - 1][r - 1] = 1;
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void adjlist(int vertices, int edges, bool type)
{
    cout << "Adjacency list graph: " << endl;
    vector<int> graphlist[vertices];
    for (int i = 0; i < edges; i++)
    {
        int r, c;
        cout << "Enter row number: ";
        cin >> r;
        cout << "Enter column number: ";
        cin >> c;
        graphlist[r].push_back(c);
        if (!type)
        {
            graphlist[c].push_back(r);
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        cout << i << "-> ";
        for (int j = 0; j < graphlist[i].size(); j++)
        {
            cout << graphlist[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    cout << "Enter number of vertices: ";
    int vertices;
    cin >> vertices;
    bool type = false;
    cout << "enter graph type: ";
    string graphtype;
    cin >> graphtype;
    if (graphtype == "directed")
    {
        type = true;
    }
    cout << "Enter number of edges: ";
    int edges;
    cin >> edges;
    // adjmat(vertices, edges, type);
    adjlist(vertices, edges, type);
    return 0;
}