class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        if (root == nullptr) return output;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* current = st.top();
            st.pop();

            output.push_back(current->val);


            if (current->right != nullptr) st.push(current->right);
            if (current->left  != nullptr) st.push(current->left);
        }

        return output;
    }
};