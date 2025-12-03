#include<bits/stdc++.h>
using namespace std ; 
struct TreeNode { 
     int val ; 
     TreeNode* left  , * right;  
     TreeNode(int x ) : val(x), left(nullptr) , right(nullpyt) {} 
      
}
class Solution { 
     public :  
     vector<TreeNode*> generateTree(int n ) {  
        if(i <=  1) {
            return 0 ; 
        }
        int total  = 0 ; 
        for(int i =1 ; i<= n ; i++){ 
             int left = generateTree(i -1) ; 
             int right =  generateTree(n- 1 ) ; 
             total += left * right ; 
        }
        return total ; 
     }
};