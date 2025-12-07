#include <vector>
#include <unordered_map>
using namespace std;

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
private:
    unordered_map<int, int> freqMap;  // Luu tan suat cua moi tong
    int maxFreq = 0;                   // Tan suat lon nhat
    
    // Ham tinh tong cua subtree
    int dfs(TreeNode* node) {
        if(!node) return 0;  // Node rong = tong 0
        
        // Tinh tong cay con trai
        int leftSum = dfs(node->left);
        
        // Tinh tong cay con phai
        int rightSum = dfs(node->right);
        
        // Tong cua subtree hien tai = trai + phai + gia tri node
        int currSum = leftSum + rightSum + node->val;
        
        // Tang tan suat cua tong nay
        freqMap[currSum]++;
        
        // Cap nhat tan suat lon nhat
        maxFreq = max(maxFreq , freqMap[currSum]);
        
        // Tra ve tong de node cha su dung
        return currSum;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root) return {};
        
        // Buoc 1: Tinh tong tat ca subtree va dem tan suat
        dfs(root);
        
        // Buoc 2: Thu thap cac tong co tan suat cao nhat
        vector<int> result;
        for(auto& p : freqMap) {
            if(p.second == maxFreq) {
                result.push_back(p.first);
            }
        }
        
        return result;
    }
};