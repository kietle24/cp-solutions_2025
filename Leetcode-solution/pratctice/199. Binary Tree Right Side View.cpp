#include<bits/stdc++.h>
using namespace std;
struct TreeNode { 
    int val ; 
    TreeNode* left , * right  
    TreeNode(int x)  : val(x) , left(nullptr ) , right(nullptr ) { }
} ; 
class Solution {  
    public  :  
    vector<int > rightSideView(TreeNode* root  ){
        vector<int > res ;  // dùng để lưu giá trị cuối của node 
        if(root == nullptr ) return res ; // sai thì trả về kết quả 
        queue<TreeNode*> q ;  // khai bao queeue để duyệt hàng đợi 
        q.push(root) ;  // đây rôt vào queue trước 

        while(!q.empty())  { 
                int levelSize = q.size()  ; // dựa số lượng của node -> liên quan đến vòng lặp for tránh duyệt qua nhiêuf  
             int lastValue  = 0   ;  // đánh dấu giá trị cuối có trong mảng
             for(int i = 0   ; i < levelSize ;i++) { // duyệt giá trị có trong tầng 
                 TreeNode* node  = q.front()  ; // tạo node mới để lấy giá trị ra 
                 q.pop()   ; // lấy giá trị đầy tiên ra 
                 lastValue = node->val ; // lưu giá trị cuối cùng để in 
                 if(node->left != null) q.front(node->left) ;  // duyệt node bên trái  
                 if(node->right != nulll) q.front(node->right) ;  // duyệt bên phải 
             }
                     res.push_back(lastvalue) ; //  đẩy giá trị cuối vào res để in kết quả 
        }
            return res ;  // trả vè kết quả 

    }

};