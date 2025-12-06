    // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @class Solution
 * @brief Calculates the sum of all root-to-leaf binary numbers in a binary tree.
 * 
 * This class provides functionality to traverse a binary tree and compute the sum
 * of all numbers formed by root-to-leaf paths, where each path represents a binary number.
 * 
 * Example:
 *     Input: [1,0,1,0,1,0,1]
 *            1
 *           / \
 *          0   1
 *         / \ / \
 *        0  1 0  1
 *     Output: 22
 *     Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 */

class Solution {
public:
    /**
     * @brief Computes the sum of all root-to-leaf binary numbers.
     * 
     * @param root Pointer to the root node of the binary tree
     * @return int The sum of all binary numbers formed by root-to-leaf paths
     * 
     * Time Complexity: O(n) where n is the number of nodes in the tree
     * Space Complexity: O(h) where h is the height of the tree (recursion stack)
     */
    int sumRootToLeaf(TreeNode *root) {
        int total = 0;
        dfs(root, 0, total);
        return total;
    }

private:
    /**
     * @brief Helper function that performs depth-first search to calculate path sums.
     * 
     * This function traverses the tree using DFS, building binary numbers by treating
     * each path from root to leaf as a binary representation. At each node, it shifts
     * the current path sum left by one bit (multiplies by 2) and adds the current node's value.
     * 
     * @param root Pointer to the current node being processed
     * @param pathsum The accumulated binary number value from root to current node
     * @param total Reference to the variable storing the cumulative sum of all complete paths
     * 
     * Base case: When a leaf node is reached (both children are NULL), the path sum
     * is added to the total.
     */
    void dfs(TreeNode* root, int pathsum, int &total) {
        if(root == nullptr) return;
        
        pathsum = pathsum * 2 + root->val;
        
        if(root->left == nullptr && root->right == nullptr) {
            total += pathsum;
            return;
        }
        
        dfs(root->left, pathsum, total);
        dfs(root->right, pathsum, total);
    }
};