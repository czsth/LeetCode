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
    bool isAnc(TreeNode *root, int key) {
        while (root) {
            if (root->val < key) root = root->right;
            else if (root->val > key) root = root->left;
            else return true;
        }
        return false;
    }
    bool isComAnc(TreeNode *root, int small, int big) {
        return isAnc(root, small) && isAnc(root, big);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = min(p->val, q->val), big = max(p->val, q->val);
        while (true) {
            if (isComAnc(root->left, small, big)) root = root->left;
            else if (isComAnc(root->right, small, big)) root = root->right;
            else return root;
        }
    }
};

//其实想了一下又觉得傻逼了，其实很简单
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = min(p->val, q->val), big = max(p->val, q->val);
        while (true) {
            if (root->val > big) root = root->left;
            else if (root->val < small) root = root->right;
            else return root;
        }
    }
};
