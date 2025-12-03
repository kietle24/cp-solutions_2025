#include<bits/stdc++.h>
using namespace std ; 
int valudes[] = {300,200 , 400 , 500} ; 
int weights[] = {2 , 1 , 5 , 3 } ; 
int max(int a , int b )  {  
     return (a >  b ) ? a : b ; 
}
int Knapsack_Algorithm(int capacity  , int n )  { 
      cout  <<  "Knapsack_Algorithm  : (" << capacity   << "," << n  << ")\n " ; 
      if(n ==  0  || capacity == 0 )
       return 0 ; 
      if(weights[n-1 ] >  capacity  ) 
      return Knapsack_Algorithm(capacity , n- 1 ) ; 
      else  { 
         int include_item  = valudes[n- 1] + Knapsack_Algorithm(capacity - weights[n-1 ], n -1 ) ; 
         int exclude_item = Knapsack_Algorithm(capacity , n -1  ) ; 
         return max(include_item , exclude_item ) ; 
      }
}
int main () { 
     int n =  sizeof(valudes) / sizeof(valudes[0]) ; 
     int capacity  = 10  ; 
     cout <<"\n Maximum value iin KnapStack " << Knapsack_Algorithm(capacity ,n ) << endl ;  
     return 0; 
}