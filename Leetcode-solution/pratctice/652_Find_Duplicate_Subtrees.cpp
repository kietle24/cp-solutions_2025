#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Định nghĩa node của cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    vector<int> res = s.preorderTraversal(root);

    cout << "Preorder: ";
    for (int val : res) cout << val << " ";
    cout << endl;

    return 0;
}
