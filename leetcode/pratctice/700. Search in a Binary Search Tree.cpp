#include<bits/stdC++.h>
using namespace std;  
struct TreeNode { 
     int val ; 
     TreeNode* left ,*  right ; 
     TreeNode(int x) : val(x ) , left(nullptr )  , right (nullptr) {}  
};
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr || root->val == val )  { 
            return root ; 
        } 
        if(val < root->val )
        {  
            return searchBST(root->left , val ) ; 
        }
        else  { 
            return searchBST(root->right  ,val ) ; 
        }
    }
};