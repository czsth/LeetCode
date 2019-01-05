/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int depth(TreeNode *root, int dep) {
        if (!root) return dep - 1;
        return max(depth(root->left, dep + 1), depth(root->right, dep + 1));
    }
public:
    int maxDepth(TreeNode* root) {
        return depth(root, 1);
    }
};