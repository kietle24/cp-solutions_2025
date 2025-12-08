#include<bits/stdc++.h>
using namespace std;
struct TreeNode  {
      int val ; 
      TreeNode* left  ,* right ; 
      TreeNode(int x): val(x) , left(nullptr ) , right(nullptr) {}
}; 
class Solution  { 
    public :
    int res =0  ; 
    
    int diameterOfBinaryTree(TreeNode* root ) {  
        if(!root ) return 0 ; 
        solve(root ) ;
        return res;
    }  
    int solve(TreeNode* root ) { 
        if(!root ) return 0 ;
        int left = solve(root -> left ) ;
        int right = solve(root -> right ) ;
        res = max(res , left + right ) ;
        return 1 + max(left , right ) ;
    }
} ; 
