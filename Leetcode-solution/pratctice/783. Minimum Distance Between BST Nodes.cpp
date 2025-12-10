#include<bits/stdc++.h>
using namespace std;  
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = INT_MAX;  // Khởi tạo với giá trị lớn nhất để tìm min
    TreeNode* prev = nullptr;  // Lưu nút trước đó trong in-order traversal
    
    int minDiffInBST(TreeNode* root) {
        solve(root);
        return res;         
    }
    
    // In-order traversal: trái -> gốc -> phải (cho BST tăng dần)
    void solve(TreeNode* root) {  
        if(!root) return;
        
        // Duyệt cây con trái trước
        solve(root->left);
        
        // Xử lý nút hiện tại
        if(prev != nullptr) {
            // Tính khoảng cách với nút trước đó
            res = min(res, root->val - prev->val);
        }
        
        // Cập nhật prev cho lần duyệt tiếp theo
        prev = root;
        
        // Duyệt cây con phải
        solve(root->right);
    } 
};

/*
VÍ DỤ:
Cây BST:      4
             / \
            2   6
           / \
          1   3

In-order traversal: 4 → 2 → 3 → 6

Quá trình tính:
- Duyệt đến 1: prev = null → bỏ qua
- Duyệt đến 2: res = min(INT_MAX, 2-1) = 1, prev = 2
- Duyệt đến 3: res = min(1, 3-2) = 1, prev = 3
- Duyệt đến 4: res = min(1, 4-3) = 1, prev = 4
- Duyệt đến 6: res = min(1, 6-4) = 1, prev = 6

Kết quả: 1
*/