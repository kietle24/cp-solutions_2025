#include<bits/stdc++.h>
using namespace std ; 
long long calculateFunction(long long n) {
if(n %2 == 0 ) return n / 2 ; 
if (n %2 != 0 ) return -(n+1)/2 ; 

}

int main () {
    long long n ; 
    cin >> n ; 
    cout << calculateFunction(n) ;
    return 0 ;
}