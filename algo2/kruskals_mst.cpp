// KRUSKAL's MST ALGORITHM

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


const int maxN = 1e5; // maximum number of vertices
int parent[maxN]; // create a parent array to store each vertice's parents

// create a vector to store edges
// main pair's first - > the weight of the edges. and the other pair will store
// the vertices that is connected to that edge
vector<pair<int,pair<int,int>>> edges;

// it will find the parent ( root ) of the given vertex
int find(int x){
    // if its parent is already itself. Then, nothing needs to change.
    if ( parent[x] == x )   return x;
    
    // otherwise, find its parent and return it
    int parentX = find(parent[x]);
    parent[x] = parentX;
    
    return parent[x];
}
// this function gets 2 seperate connected graphs whose roots are X and Y together.
// and eventually, make them 1 connected graph whose root is X
void birles(int x, int y){
    
    int parentX = parent[x];
    int parentY = parent[y];
    
    // set parentY's root as parentX. so X will be the root of all connected graph.
    parent[parentY] = parentX;
}

int main(){
    
    
    // KRUSKAL's MST ALGORITHM
    int shortest_path = 0;
    int n, m;
    cin >> n >> m; // n is number of vertices, m is number of edges
    
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w; // u is first vertex, v is second vertex, and w is the weight of the edge
        
        edges.push_back( {w, {u, v}} );
    }
    
    for(int i = 1; i <= n; i++){
        parent[i] = i; // set all vertices' parent as themselves.
    }
    
    sort(edges.begin(), edges.end()); // sort the edges by their weights.
    
    // explore the edges in order
    for (int i = 0; i < m; i++){
        auto myEdge = edges[i];
        
        int w = myEdge.first;
        int u = myEdge.second.first;
        int v = myEdge.second.second;
        
        // find their parents and decide if there will be a cycle when they are connected
        if ( find(u) != find(v) ){
            birles(u, v);
            shortest_path += w;
        }
    }
    cout << shortest_path << endl;
    
    return 0;
}
