class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        inorder(root, k, res );
        return res ;
    }

private:
    void inorder(TreeNode* node, int& k, int& res) {
        if (!node || k == 0) return;
        inorder(node->left, k, res);
        if (--k == 0) { res = node->val; return; }
        inorder(node->right, k, res);
    }
};
