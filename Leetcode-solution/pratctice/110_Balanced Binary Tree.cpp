#include <bits/stdc++.h>
using namespace std;

// Cấu trúc node cơ bản của cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Hàm kiểm tra cây có cân bằng không
    bool isBalanced(TreeNode* root) {
        // Nếu cây rỗng => mặc định cân bằng
        if (root == nullptr) 
            return true;

        // Nếu chênh lệch độ cao giữa 2 cây con > 1 => mất cân bằng
        if (abs(height(root->left) - height(root->right)) > 1) 
            return false;

        // Gọi đệ quy cho hai cây con để đảm bảo toàn cây đều cân bằng
        // Trả về true chỉ khi cả trái và phải đều cân bằng
        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    // Hàm phụ để tính độ cao (height) của cây con
    int height(TreeNode* node) {
        // Nếu node rỗng => chiều cao = 0
        if (node == nullptr) 
            return 0;

        // Ngược lại, tính độ cao bằng 1 + max(độ cao của cây con trái, cây con phải)
        return 1 + max(height(node->left), height(node->right));
    }
};
/*
height(3)
 ├── height(9)
 │     ├── height(nullptr) → 0
 │     ├── height(nullptr) → 0
 │     └── return 1
height(20)
 ├── height(20->left)  → gọi height(15)
 │      ├── height(15->left)  → nullptr → 0
 │      ├── height(15->right) → nullptr → 0
 │      └── return 1 + max(0,0) = 1
 │
 ├── height(20->right) → gọi height(7)
 │      ├── height(7->left)  → nullptr → 0
 │      ├── height(7->right) → nullptr → 0
 │      └── return 1 + max(0,0) = 1
 │
 └── return 1 + max(1,1) = 2



*/