#include<bits/stdc++.h>
using namespaces std ; 
struct TreeNode {  
     int val ; 
     TreeNode* left  , * right ; 
TreeNode(int x ) : val(x ) , left(nullptr ) , right(nullptr) { }
}; 
class Solution  { 
    public  : 
    int numTrees(int n)  { 
         if( n <=  1 )  { 
            return 1;   
         } 
         int total  = 0 ; 
        for(int i =0 ; i <= n ;i++ ) {  
            int left = numTrees(i -1 ) ; 
            int right = numTrees(n - 1 )   ; 
            total  += left * right  ; 
        
        }
        return total  ; 
    }
};