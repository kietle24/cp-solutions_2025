#include<bits/stdc++.h>
using namespace std ; 
struct TreeNode { 
     int val ; 
     TreeNode* left , *right  ; 
     TreeNode(int x )  : val(x) , left(nullptr ) , right(nullptr )  {} 
}; 
//  max sum=max(tổng caˊc node treˆn một đường hợp lệ)
#include <climits>

class Solution {
    int ans = INT_MIN;   // lưu giá trị lớn nhất toàn cục

    int dfs(TreeNode* root) {
        if (!root) return 0;

        // loại bỏ nhánh âm vì sẽ làm giảm tổng
        int leftMax  = max(0, dfs(root->left));
        int rightMax = max(0, dfs(root->right));

        // cập nhật kết quả toàn cục nếu đi qua node này
        ans = max(ans, root->val + leftMax + rightMax);

        // trả về nhánh tốt nhất đi lên cha (chỉ chọn 1 nhánh)
        return root->val + max(leftMax, rightMax);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
