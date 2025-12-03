#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(root, targetSum, 0, temp, result);
        return result;
    }

private:
    void dfs(TreeNode* root, int targetSum, int sum, vector<int>& temp, vector<vector<int>>& result) {
        if (root == NULL) return;

        temp.push_back(root->val);
        sum += root->val;

        if (root->left == NULL && root->right == NULL && sum == targetSum) {
            result.push_back(temp); 
        }

        dfs(root->left, targetSum, sum, temp, result);
        dfs(root->right, targetSum, sum, temp, result);

        temp.pop_back(); 
    }
};
