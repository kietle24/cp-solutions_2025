#include<bits/stdc++.h>
using namespace std ;  
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution  {  
     public  :   
     unordered_set <int > s ;  
     bool findTarget(TreeNode* root  , int k)   {  
         if(root == nullptr ) return  false ; 
         if(s.count(k - root->val ) ) return true ;  // ham count kiem tra gia tri co trong hashma p 
            s.insert(root->val ) ; 
        return findTarget(root->left , k ) || findTarget(root->right ,  k ) ; 

     }
}; 


/*
mục tiêu  : xét các cặp số trong cây có giá trị sum bằng k ->true  
Phương Pháp  : 
method 1  :  (innoder Travesal  ) 
o(n^2 )  ?  
1 Do an Inorder Travelsal of the given BST and store it an Array  
2 Use 2 point abbtrach to find it array has a pair with given sum  

sử dụng phương pháp hasing (bảng băm )để giải  cách nhanh và dễ nhất 
vd 
node1->val + node2->val == k

     5
    / \
   3   6
  / \   \
 2   4   7
đề bài  : 
     5
    / \
   3   6
  / \   \
 2   4   7
Hỏi: có hai node nào trong cây có tổng bằng 9 không? 
→ Rõ ràng có nhiều cặp đúng tổng 9:
(5,4), (3,6), (2,7) 




*/






