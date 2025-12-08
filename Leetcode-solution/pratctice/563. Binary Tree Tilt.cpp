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
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int total = 0;  // Biến toàn cục lưu tổng tilt của toàn bộ cây
    
    // Hàm đệ quy tính tổng giá trị cây con và cập nhật tilt
    int solve(TreeNode* root) { 
        // Base case: nút null có tổng = 0
        if(!root) return 0; 
        
        // Tính tổng giá trị của cây con bên trái
        int leftsum = solve(root->left); 
        
        // Tính tổng giá trị của cây con bên phải
        int rightsum = solve(root->right); 
        
        // Tính tilt của nút hiện tại và cộng vào tổng
        // Tilt = |tổng cây trái - tổng cây phải|
        total += abs(leftsum - rightsum);
        
        // Trả về tổng giá trị của cây con gốc tại root
        // để nút cha có thể tính tilt của nó
        // Tổng = tổng trái + tổng phải + giá trị nút hiện tại
        return leftsum + rightsum + root->val;
    }
    
    // Hàm chính tính tổng tilt của cả cây
    int findTilt(TreeNode* root) {
        solve(root);  // Gọi hàm đệ quy để tính toán
        return total;  // Trả về tổng tilt đã tích lũy
    }
};

/*
VÍ DỤ MINH HỌA:
Cây:      4
         / \
        2   9
       / \   \
      3   5   7

QUÁ TRÌNH THỰC THI (Post-order traversal):

1. Nút 3 (lá):
   - leftsum = 0, rightsum = 0
   - total += |0 - 0| = 0
   - return 0 + 0 + 3 = 3

2. Nút 5 (lá):
   - leftsum = 0, rightsum = 0
   - total += |0 - 0| = 0
   - return 0 + 0 + 5 = 5

3. Nút 2:
   - leftsum = 3 (từ nút 3)
   - rightsum = 5 (từ nút 5)
   - total += |3 - 5| = 2 → total = 2
   - return 3 + 5 + 2 = 10

4. Nút 7 (lá):
   - leftsum = 0, rightsum = 0
   - total += |0 - 0| = 0
   - return 0 + 0 + 7 = 7

5. Nút 9:
   - leftsum = 0
   - rightsum = 7 (từ nút 7)
   - total += |0 - 7| = 7 → total = 9
   - return 0 + 7 + 9 = 16

6. Nút 4 (root):
   - leftsum = 10 (từ cây con trái)
   - rightsum = 16 (từ cây con phải)
   - total += |10 - 16| = 6 → total = 15
   - return 10 + 16 + 4 = 30 (không được dùng)

KẾT QUẢ: total = 15
*/