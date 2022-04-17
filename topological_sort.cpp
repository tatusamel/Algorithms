#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int maxn = 100005;
vector<int> adj[maxn];
vector<bool> visited(maxn);

// aslinda dfs yapiyoruz.
void topological_sort(int u, stack<int>& st){
    
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            topological_sort(v,st);
        }
    }
    // bu node ile isim bittigi zaman yani dfs ile gidebilecegim en son
    // noktaya kadar gittigim zaman bu nodeu stacke atiyoruz
    // stack olmasinin sebebi de en sonda tersini almamiz gerektiginden dolayi
    // o yuzden dolayi
    st.push(u);
     
}

int main(){
    
    int n,m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    
    // graph connnected olmayabilir bu yuzden tum nodelar icin denememiz gerekebilir
    // yani ilk dfs bittiginda hala visit edilmeyen nodelar olabilir
    for(int i = 1; i <= n; i++){
        
        if ( visited[i] )   continue;
        
        stack<int> st;
        topological_sort(i,st);
        
        int sz = st.size();
        for(int j = 0; j < sz; j++){
            cout << st.top() << ' ';
            st.pop();
        }
        cout << '\n';
    }
    
    
    return 0;
}
