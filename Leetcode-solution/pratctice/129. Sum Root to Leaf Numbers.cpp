#include<bits/stdc++.h>
using namespace std ; 
 struct TreeNode { 
    int val ; 
    TreeNode * left  , * right ; 
    TreeNode(int x ) : val(xa) , left(nullptr ) , right(nullptr )  { }
 } ; 
 class Solution  { 
    long long  ans =  0 ; 
    void dfs(TreeNode* root , long long  val )  { 
         
        if(!root ) return ; 
        val = val * 10  + root->val  ;  
        if(!root->left && !root->right ){
             ans += val ; 
             return ; 
        }
        dfs(root->left , val ) ; 
        dfs(root->right , val ) ; 
    }   
public  : 
    int maxPathSum(TreeNode * root ) { 
        if(!root) return 0; 
        dfs(root, 0 ) ; 
        return ans  ;
    
    }
 };
/* 
Gia su cho minh hoa cay nhi phan co cau truc sau  d:  
        1
       / \
      2   3
mô tả bài toán duyệt từ gốc -> node lá sao cho : 1-> 2 = 12 
                                                 1-> 3 = 13 
                                                kết quả cần trả về 25 

b1  : 
root =1 
val = 0   ; 
val* = val*10 + node->val 
b2 
root = 2 
node = 2 
val tc  = 1 
val sau = 12 
luu ans  =12 
buoc 3  : 
root =3 
val  = 1  
val moi  =13 
-> 12 + 13  = 25 
*/