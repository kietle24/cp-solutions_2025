#include<bits/stdc++.h>
using namespace std ;  
struct TreeNode {  
    int val ;  
    TreeNode* left , * right   ; 
    TreeNode(int x ) : val(x) , left(nullptr) , right(nullptr) {} 
} ; 
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res ; 
        if(!root ) return res ; 
        dfs(root,"" , res) ; 
        return res ; 
        
    }
    void dfs(TreeNode* node , string path , vector<string>& res) {  
        if(!node) return  ; // dieu kien dung  
        path += to_string(node->val) ;  // cap nhat duong di hien tai 
        if(!node->left && !node->right) 
        res.push_back(path) ; // kiem tra node la 
    }else  {  
        path += '->'; 
        dfs(node->left , path ,res) ; 
        dfs(node->right , path , res ) ; 
    }
}