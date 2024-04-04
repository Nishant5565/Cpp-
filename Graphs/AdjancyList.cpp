// * Program to implement Adjacency List in Graphs 

#include <iostream>
#include <vector>
using namespace std;

// ? What is Graph ?
// * A graph is a data structure that consists of the following two components:
// * 1. A finite set of vertices also called as nodes.
// * 2. A finite set of ordered pair of the form (u, v) called as edge. The pair is ordered because (u, v) is not same as (v, u) in case of a directed graph(di-graph). The pair of the form (u, v) indicates that there is an edge from vertex u to vertex v. The edges may contain weight/value/cost.

// Note : Degree of a vertex is the number of edges incident on it. Indegree of a vertex is the number of edges coming into the vertex. Outdegree of a vertex is the number of edges going out of the vertex.

// ? What is Adjacency List ?
// * An array of lists is used. The size of the array is equal to the number of vertices. Let the array be an array[]. An entry array[i] represents the list of vertices adjacent to the ith vertex. This representation can also be used to represent a weighted graph. The weights of edges can be stored in the nodes of the linked lists.

// * Program to implement Adjacency List in Graphs
// * A structure to represent an adjacency list node

