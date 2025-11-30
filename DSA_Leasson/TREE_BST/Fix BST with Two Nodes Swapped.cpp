/*
Mục tiêu
Tìm 2 node bị hoán đổi và đổi lại giá trị của chúng (không đổi cấu trúc cây).
TH1 
bd : 
    3
   / \
  1   4
     /
    2
 nhưng ai đó đổi 3 - 2 -> sai 

    2
   / \
  1   4
     /
    3
TH2 :  
      20
     /  \
   60     80
  / \    / \
 4  10  8  100
thành ra 
      20
     /  \
   8     80
  / \   /  \
 4  10 60  100
-> sai vị trí 

Tại vì sao phải check theo thứ tự tăng dần  ?  
phải tuân thủ quy tắt Tất cả giá trị bên trái < node hiện tại < tất cả giá trị bên phải
Nên khi ta duyệt cây theo thứ tự trái → gốc → phải (inorder traversal), ta luôn như vậy nếu không muốn phá vỡ quy tắt  
Nếu không check thứ tự tăng dần, ta không thể biết sai ở đâu 

      20
     /  \
    8    80
   / \   / \
  4  10 60 100

👉 [4, 8, 10, 20, 60, 80, 100] (tăng dần hoàn hảo)

Cây sai:
      20
     /  \
   60    80
  / \   / \
 4  10  8 100
👉 [4, 60, 10, 20, 8, 80, 100]

| Bước | prev | curr | So sánh    | Vi phạm?  | Ghi nhận                    |
| ---- | ---- | ---- | ---------- | --------- | --------------------------- |
| 1    | 4    | 60   | 60 > 4 ✅   | ❌         | -                           |
| 2    | 60   | 10   | 10 < 60 ❌  | ✅         | `first = 60`, `second = 10` |
| 3    | 10   | 20   | 20 > 10 ✅  | ❌         | -                           |
| 4    | 20   | 8    | 8 < 20 ❌   | ✅ (lần 2) | `second = 8`                |
| 5    | 8    | 80   | 80 > 8 ✅   | ❌         | -                           |
| 6    | 80   | 100  | 100 > 80 ✅ | ❌         | -                           |

if(prev != nullptr && root->val  < pre)







*/
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
 
class Solution {
public:
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *prev = nullptr;

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->val < prev->val) {    // phát hiện nghịch thế
            if (!first) 
            first = prev;           // node sai đầu tiên
            second = root;                      // node sai thứ hai
        }

        prev = root;                            // cập nhật prev
        inorder(root->right);
    }
};
