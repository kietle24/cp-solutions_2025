#include<bits/stdc++.h>
using namespace std ; 
int main(){ 
      int n , ans =0 ;
      int a[] = {5 ,  4,3 , 2 , 1 } ;    
      cin >> n ; 
     for(int i =0 ; i < 5  ; i++) { 
         ans += n/a[i] ; // 12 + 12 
         n = n % a[i] ; 

     }
     cout << ans  ; 
     return 0;
}