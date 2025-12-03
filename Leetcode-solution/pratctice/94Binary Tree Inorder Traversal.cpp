#include<bits/stdc++.h>
using namespace std ; 
class Solution : 
    public : 
    vector<int> inorderTraversal(TreeNode* root ) {  
        vector<int > result ; 
        if(root == nullptr  ) return result  ; 
        stack(TreeNode*) st ; 
        TreeNode* cur = root ;  
        while(cur ! = nullptr || st.empty()) { 
            while(cur->nullptr | !st.empty()){
            st.push(cur) ; 
            cur  = curr->left ; 

        }
        cur = st.top()   ;
        st .pop() ; 
        result.push_back(cur->val ) ; 
        cur = cur->right ; 
    }
    
}

    