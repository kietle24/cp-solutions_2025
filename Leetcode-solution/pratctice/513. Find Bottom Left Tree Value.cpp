#include<bits/stdc++.h>
using namespace std ; 
struct TreeNode { 
     int val ; 
     TreeNode* left , *right  ; 
     TreeNode(int x )  val(x) , left(nullptr ) , right(nullptr ) { } 
} ; 
class Solution  { 
    public :
    int findBottomLeftValue(TreeNode * root )  {  
        if(!root ) return -1; 
        queue<TreeNode* > q; 
         q.push(root ) ; 
         TreeNode* first  = root ; 
         while(!q.empty()) { 
            int levelSize= (int)q.size() ; 
            first = q.front(); 
            for(int i = 0 ;  i  < levelSize ; i++)  { 
                TreeNode* node = q.front(); 
                q.pop(); 
                if(node->left)q.push(node->left ) ; 
                if(node->right )q.push(node->right ) ; 
            }
         }
         return first->val  ; 
    }
} ; 

/*
VD 
        1
      /   \
     2     3
    / \     \
   4   5     6
  /
 7
 
khoi tao  : 
queue<TreeNode* > q ;  
q.push(root ) ; //  1 
q = [ 1] 
firstValue = 1 ;  


 */
 