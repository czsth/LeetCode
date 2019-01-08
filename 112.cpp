/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//这个题不难，但是我WA了三次，原因在于瞎剪枝
//以为节点值没有负数，或者单调
//都是我意淫出来的
//这个事情告诉我要仔细审题
//WA有点丢脸
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (sum == root->val && !root->left && !root->right) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};