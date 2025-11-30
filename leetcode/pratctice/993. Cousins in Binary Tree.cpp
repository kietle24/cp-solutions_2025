#include<bits/stdc++.h>
using namespace std ;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *findParent(TreeNode *root, int x, int depth, int &outDepth)
{
    if (!root)
        return NULL;

    if (root->left && root->left->val == x)
    {
        outDepth = depth + 1;
        return root;
    }
    if (root->right && root->right->val == x)
    {
        outDepth = depth + 1;
        return root;
    }

    TreeNode *p = findParent(root->left, x, depth + 1, outDepth);
    if (p)
        return p;

    return findParent(root->right, x, depth + 1, outDepth);
}

bool isCousins(TreeNode *root, int x, int y)
{
    int dx = -1, dy = -1;

    TreeNode *px = findParent(root, x, 0, dx);
    TreeNode *py = findParent(root, y, 0, dy);

    return dx == dy && px != py;
}
