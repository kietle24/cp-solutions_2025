class Solution  { 
     public :  
      bool hasPathSum(Tree* root , int targerSum) {  
          if(!root)  {  
            return false ; 
          }
          if(!root->left && !root->right ) { 
              return targetSum == root->val  ; 
          }
          if(hasPathSum(root->left , targerSum -root->val ))  { 
             return true ; 
          }
          if(hasPathSum(root->right , targerSum-  root->val ))  {
             return true ; 
          }
          return false ;
      }

};