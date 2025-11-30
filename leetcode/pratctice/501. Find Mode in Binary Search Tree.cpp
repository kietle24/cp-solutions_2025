#include<bits/stdc++.h>
using namespace std ; 
struct TreeNode { 
     int val ; 
     TreeNode* left , * right ; 
     TreeNode(int x )  : val(x) , left(nullptr ) , right(nullptr ) {} 
}; 

class Solution {
public:
    int maxcount = 0;
    int count = 0;
    TreeNode* prev = nullptr;
    vector<int> modes;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && prev->val == root->val)
            count++;
        else
            count = 1;

        if (count > maxcount) {
            maxcount = count;
            modes = {root->val}; // reset danh sách
        } else if (count == maxcount) {
            modes.push_back(root->val); // thêm vào danh sách
        }

        prev = root;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        inorder(root);
        return modes;
    }
};

/*
mục tiêu (mode tan suat xuat hien nhieu nhat): tìm tất cả các node xuất hiện nhiều nhất trong một binary search 
ý tưởng : 
khi duyệt bẳng inoder ta được một dãy giá trị tăng dần các giá trị 
các giá trị giống nhau sẽ năm liền kề -> đếm tần xuất các giá trị liên kề nhau 
sử dụng 
prev : giá trị trước đó 
count  : số lần lập 
maxcount : số lần xuất hiện nhiều nhất 

*/