// Graphs in C++ using STL

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph {

public:
     unordered_map < int,  list <int> > adj;

     void addEgde( int u, int v, bool direction ){
          // direction =0 means graph is not directed 
          adj[u].push_back(v);
          if(direction == 0){
               adj[v].push_back(u);
          }
     }

     void printAdjList(){
          for( auto i:adj){
               cout << i.first << "->";
               for (auto j:i.second){
                    cout << j << " ";
               }
               cout << endl;
          }
     }

     void AdjMatrix(){
          int n = adj.size();
          int adjMat[n][n];

          for (int i = 0; i < n; i++){
               for (int j = 0; j < n; j++){
                    adjMat[i][j] = 0;
               }
          }
          for (int i = 0; i < n; i++){
               for (auto j:adj[i]){
                    adjMat[i][j] = 1;
               }
          }
          for (int i = 0; i < n; i++){
               for (int j = 0; j < n; j++){
                    cout << adjMat[i][j] << " ";
               }
               cout << endl;
          }
     }

};

int main(){
     int n; 
     cout << " Enter the number of nodes" << endl;
     cin >> n;

     int m ;
     cout << " Enter the number of edges" << endl;
     cin >> m;

     graph g;
     cout << " Enter the Vertices " << endl;

     for ( int i =0 ; i < m; i++ ){
          int u, v;
          cin >> u >> v;
          g.addEgde(u,v,0);
     }

     g.printAdjList();

}