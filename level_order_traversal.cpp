#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// bfs and level order traversal ( printing )
void bfs(int u, vector<bool>& visited, vector<int> adj[]){
    
    // first - > v ,    second  -> height
    queue<pair<int,int>> q;
    visited[u] = true;
    
    q.push({u,0});
    cout << u << '\n'; // print root
    
    int height = 0;
    while(!q.empty()){
        
        auto top = q.front(); q.pop();
        if ( height != top.second ){
            cout << '\n';
            height = top.second;
        }
        
        for ( int v : adj[top.first] ){
            if ( !visited[v] ){
                visited[v] = true;
                q.push({v,top.second+1});
                cout << v << ' ';
            }
        }
    }
}


// find each sumation of vertices in every connected subgraph
// Tum connected componentlerin uzerinde yazan sayilarin toplamini bul, ayri ayri
int dfs(int u, vector<bool>& visited, vector<int> adj[]){
    visited[u] = true;
    int sum = u;

    for( int v : adj[u] ){
        if (!visited[v]){
            sum += dfs(v, visited, adj);
        }
    }
    return sum;

}
int main(){
    
    int n,m; cin >> n >> m;
    
    
    vector<int> adj[n+1];
     
    // for adjlist
    for(int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        
        adj[u].push_back(v); // directed olarak aldik
    }
    
    vector<bool> visited(n+1, false);

    for(int i = 1; i <= n ; i++){
        if (!visited[i]) {
            cout << dfs(i, visited, adj) << '\n';
        }
    }
    
}

 

