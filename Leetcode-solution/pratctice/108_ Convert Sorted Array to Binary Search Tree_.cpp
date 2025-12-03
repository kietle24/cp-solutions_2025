#include <iostream>
#include <vector>
using namespace std;

// Định nghĩa cấu trúc TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Hàm để in cây theo thứ tự Pre-order (Node -> Left -> Right)
void printPreOrder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    cout << node->val << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructTreeFromArray(nums, 0, nums.size() - 1);
    }

    TreeNode* constructTreeFromArray(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        int mid = left+(right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = constructTreeFromArray(nums, left, mid - 1);
        node->right = constructTreeFromArray(nums, mid + 1, right);
        return node;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sol.sortedArrayToBST(nums);
    
    cout << "Cay theo thu tu Pre-order: ";
    printPreOrder(root);

    
    return 0;
}