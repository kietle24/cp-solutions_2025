#include<bits/stdc++.h>
using namespace std;
void solve(int n){
    for(int i = 1; i <= n; i++){
        if(i > 1) cout << " that ";
        if(i % 2 == 1) cout << "I hate";
        else cout << "I love";
    }
    cout << " it" << endl;
}
int main() { 
     int n ; 
     cin >> n ; 
     solve(n);
     return 0;
}