// Definition for a binary tree node.
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
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        inorder(root, k, res);
        return res;
    }

private:
    void inorder(TreeNode* node, int& k, int& res) {
        if (!node || k == 0) return;
        inorder(node->left, k, res);
        if (--k == 0) {
            res = node->val;
            return;
        }
        inorder(node->right, k, res);
    }
};
