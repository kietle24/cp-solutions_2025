#include<bits/stdc++.h>
using namespace std ; 
vector<int > adj[100] ; 
bool visted[100];  
void BFS(int start) {  
    queue<int> q ; 
    visted[start] = true; 
    q.push(start)  ; 
    while(!q.empty()) { 
         int  u= q.front() ; 
         q.pop(); 
         cout << u << " "  ;
          for(int v : adj[u]) { 
            if(!visted[v]){
                 visted[v] =true ; 
                 q.push(v) ; 
            }
          }
    }
}
int main () {
     int n , m ; 
     cin >> n >> m ; 
     for(int i =0 ;  i  < m  ; i++) { 
         int u , v ; 
         cin >> u >> v ; 
         adj[u].push_back(v) ; 
         adj[v].push_back(u) ; 
     }
     cout << "BFS :"; 
     BFS(1) ; 
     return 0 ; 
}