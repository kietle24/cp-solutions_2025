#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(root == NULL) return true;
        int x = root->left->val;
        int y = root->right->val;
        return (root->val == x + y);
    }
};