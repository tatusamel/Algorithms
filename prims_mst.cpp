// PRIM's MST ALGORITHM
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int prims(){
    
    // taking inputs
    // n - > number of vertices, m - > number of edges
    int n,m;
    cin >> n >> m;
    
    // first -> weight,  second -> to-vertex and index -> from vertex
    vector<pair<int,int>> adjList[n+1]; // to store connections
    vector<bool> visited(n+1); // to check if the nodes are visited
    
    // taking edge inputs
    for( int i = 0; i < m ; i++){
        // u - > from-vertex, v -> to-vertex, w -> weight of edge
        int u,v,w;
        cin >> u >> v >> w;
        
        adjList[u].push_back({w,v});
        adjList[v].push_back({w,u}); // if it's an undirected graph
        
    }
    // first->weight , second->to-vertex
    // we set weight as the first element of the pair because we want it to be sorted by weight
    priority_queue<pair<int,int>> pq;
    
    // firstly, add all edges that is connected to vertex 1 to min priority queue, because we start from vertex 1
    for ( auto p : adjList[1] ){
        // p.first is weight
        // p.second is to-vertex
        int w = p.first;
        int v = p.second;
        
        pq.push( {-w,v}); // multiply weight by -1, to make it min-heap
    }
    visited[1] = true;
    int total_cost = 0;
    
    while ( !pq.empty() ){
        // this is the edge with the minimum lenght
        auto top = pq.top();
        int w = -top.first; // multiply it back by -1 to make it as it used to be initially
        int v = top.second;
        pq.pop();
        
        if ( visited[v] )   continue;
        visited[v] = true;// now we visited node v, and we can add the adjacent nodes of node v

        total_cost += w;
        
        for ( auto p : adjList[v] ){
            // v -> from vertex
            // p.first - > weight
            // p.seoncd -> to-vertex
            if ( !visited[p.second] ){
                pq.push( {-p.first, p.second });
            }
        }
    }
    return total_cost;
}
