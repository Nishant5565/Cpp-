#include <iostream> 
#include <queue>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class graph{
    public:
     unordered_map < int, list <int> > adjList;
     vector<int> ans;
     unordered_map < int , bool > visited; 
     void addEdge(int u, int v, bool direction){
          adjList[u].push_back(v);
          if(direction == 0){
               adjList[v].push_back(u);
          }
     }

     void printAdjList(){
          for(auto i:adjList){
               cout << i.first << "->";
               for(auto j:i.second){
                    cout << j << " ";
               }
               cout << endl;
          }
     }

     void BFS(int src){
          queue<int> q;
          q.push(src);
          visited[src] = true;
          while(!q.empty()){
               int node = q.front();
               q.pop();
               ans.push_back(node);
               for(auto neighbour:adjList[node]){
                    if(!visited[neighbour]){
                         q.push(neighbour);
                         visited[neighbour] = true;
                    }
               }
          }
     }

};

int main(){
     graph g;
     // Assuming undirected graph for simplicity
     g.addEdge(0, 1, 0);
     g.addEdge(0, 2, 0);
     g.addEdge(1, 2, 0);
     g.addEdge(2, 0, 0);
     g.addEdge(2, 3, 0);
     g.addEdge(3, 3, 0);

     cout << "Adjacency List:" << endl;
     g.printAdjList();
     g.BFS(2); 
     cout << "BFS Traversal:" << endl;
     for(int i : g.ans){
          cout << i << " ";
     }
     cout << endl;

     return 0;
}