#include<bits/stdc++.h>
using namespace std; 
void solve() { 
    int a[3] ; 
    cin >> a[0] >> a[1] >> a[2] ; 
    sort(a , a + 3) ;
    cout << a[1] << endl ;
     
}
int main () { 
     int t ; 
     cin >> t ; 
     for(int i = 1 ; i <= t ; i++) { 
            solve() ;
     }
}