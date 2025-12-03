#include<bits/stdc++.h>
using namespace std ; 
struct TreeNode { 
     int val; 
     TreeNode* left , *right ; 
     TreeNode(int v) : val(v) , left(nullptr) , right(nullptr){}
}
class Solution  { 
    public : 
    bool isSymmetric(TreeNode* root ) {  
        if(root == nullptr ) return true ; //2 cai giong nhau 
        queue<TreeNode*> leftTree ; 
        queue<TreeNode*> rightTree; 
        leftTree.push(root->left);
        rightTree.push(root->right) ; 
        while(!leftTree.empty() && !rightTree.empty()) {  
            // leftTree.front() : lay phan tu dau tien cua hang doi trong leftTree ma khong xoa no di 
            TreeNode* leftNode = leftTree.front() ; 
            leftTree.pop() ; 
            TreeNode* rightNode = rightTree.front() ;
            rightTree.pop() ;
            if(leftNode == nullptr && rightNode == nullptr) continue; 
            if(leftNode == nullptr || rightNode == nullptr) return false ;  
            if(leftNode->val != rightNode->val) return false ; 
            //!important day cac node con vao hang doi de so sanh doi xung 
            leftTree.push(leftNode->left) ; 
            leftTree.push(leftNode->right) ; 
            rightTree.push(rightNode->right);
            rightTree.push(rightNode->left);
            
        }
        return true ; 
    }
}