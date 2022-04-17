
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// GLOBAL OLARAK BOYLE TANIMLIYORUZ ve fonksiyonlarda paremetre olarak eklememize gerek kalmiyor

// maxn degeri soruda n icin verilen maximum deger
const int maxn = 200005;
vector<int> adj[maxn];
vector<bool> visited(maxn);
vector<int> color(maxn); // renkleri tutmak icin, -1 ve 1 ayri birer renk olarak sayiyoruz


// normal dfsten farkli olarak parametre olarak "parent" tutuyoruz ki geldigi nodea erisimimiz
// olsun ve onun rengini bulabilelim
void dfs(int u, int p){
    
    color[u] = ( color[p] == -1 ) ? 1 : -1; // dfsten sadece bu kisim farkli
    
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v,u); // v  ->   child,   u  ->  parent oluyor
        }
    }
}

int main() {
    
    // adj list alma
    int n,m; cin >> n >> m;
    for(int i =0; i < m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // 0ı  ilk olarak 1in parenti olarak aldım ve 0in rengini -1 yaptım
    color[0] = -1;
    dfs(1,0); // 1den DFSi başlattık
    
    // dfs sonunda tum renkler verildi ve simdi renkler dogru mu diye kontrol ediyoruz
    // eger adjacent olan nodelardan renkleri ayni olan varsa biparite degildir
    for(int u = 1; u < n; u++){
        for( auto v : adj[u] ){
            if ( color[u] == color[v] ){
                cout << "Bipartite degil" << '\n';
                return 0;
            }
        }
    }
    cout << "Bipartite" << '\n';
    return 0;
}

