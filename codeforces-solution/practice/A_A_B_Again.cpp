#include<bits/stdc++.h>
using namespace std ; 
int get_sum(int t){
    int sum = 0 ; 
    while(t){
        sum += t % 10  ; 
        t = t / 10 ; 

    }
    return sum ; 
}
int main () {
    int n ;
    cin >> n ; 
    while(n--){
        int t; 
        cin >> t ; 
        cout << get_sum(t) << endl ; 
    }
}