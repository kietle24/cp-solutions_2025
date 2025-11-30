#include<bits/stdc++.h>
using namespace stds ; 
struct TreeNode {
     int val ; 
     TreeNode* left , *right ; 
     TreeNode(int x ) val(x) , left(nulltpr ) , right(nullptr ) { 

     }
}; 
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(root==NULL) return true;
        int x=root->left->val;
        int y=root->right->val;
        if(root->val==x+y) return true;
        return false;
    }
};