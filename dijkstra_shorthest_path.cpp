
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int dijkstra(){
    int n, m;
    cin >> n >> m;
    
    vector<pair<int,int>> adj[n+1];

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
 
    priority_queue<pair<int, pair<int, int>>> heap;
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, INT_MAX);
    vector<int> prev(n + 1, 0); // eger gittigi yolu isterse
 
    dist[1] = 0;
    heap.push({-0, {1, 0}});
 
    while(!heap.empty()){
        int d = -heap.top().first;
        int u = heap.top().second.first;
        int p = heap.top().second.second;
        heap.pop();
 
        if(visited[u]) continue;
        visited[u] = true;
        prev[u] = p;
 
        for(auto e : adj[u]){
            int v = e.first;
            int w = e.second;
 
            if(dist[v] > d + w){
                dist[v] = d + w;
                heap.push({-dist[v], {v, u}});
            }
        }
    }
    
    // if asks for the path
    vector<int> path;
    int curr = n;
    while(curr != 0){
        path.push_back(curr);
        curr = prev[curr];
    }
    reverse(path.begin(), path.end());
 
    // if cannot reach to node n
    if(dist[n] == INT_MAX) return -1;
    else{
        return dist[n];
        // if asks for the path, print this
        //for(auto i : path) cout << i << " ";
    }
}
 
