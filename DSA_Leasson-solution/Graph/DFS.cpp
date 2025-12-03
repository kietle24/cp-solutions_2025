#include<bits/stdc++.h>
using namespace std ; 
vector<int> adj[100] ; 
bool visted[100] ; 
void dfs(int u ) { 
     visted[u] = true ; 
    cout << u << " " ; 
     for(int v : adj[u]) {  
        if(!visted[v])
        dfs(v) ; 
     }  
}
int main () { 
     int n, m ,u, v  ; 
     cin >>  n >>  m ; 
     for(int i = 0 ; i < m  ; i++) { 
         cin >> u >> v ; 
         adj[u].push_back(v) ; 
         adj[v].push_back(u) ; // su dung trong truong hop 2 khi do thi co huong 
     }
     cout << "DFS Travesal " << " "  ; 
     dfs(1) ;
     return 0 ; 
}

