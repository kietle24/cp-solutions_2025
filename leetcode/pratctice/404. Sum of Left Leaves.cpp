class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int sum = 0;
        if (root->left != nullptr &&
            root->left->left == nullptr && root->left->right == nullptr)
            sum += root->left->val;
        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) ;
    }
};


/*
Throught before Coding : 
Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
bai toan nay can tra ve sum  1 la node le ben tay trau || 1 node le ben trai cua node (co node khac la node goc ) 
-DFS || BST  
có trường hợp đặc biệt lá bên trái và nhánh bên trái 652. Find Duplicate Subtrees
cần phân biệt giữa lá
Cụm “lá bên trái” (left leaves) không có nghĩa là tất cả node nằm bên trái của cây,
mà là các node mà bản thân chúng vừa là lá, vừa nằm ở vị trí con trái của cha chúng.
    2
   /
  3
   \
    5
“Left leaves” không phải là tất cả node nằm bên trái cây,
mà là những node lá nằm ở vị trí con trái của cha.


*/