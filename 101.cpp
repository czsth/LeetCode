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
public:
    bool isSymmetric(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        queue<TreeNode *> ltq, rtq;
        ltq.push(root->left), rtq.push(root->right);
        TreeNode *tmpl, *tmpr;
        while (!ltq.empty() && !rtq.empty()) {
            tmpl = ltq.front(), tmpr = rtq.front();
            if (!tmpl && !tmpr) {ltq.pop(), rtq.pop(); continue;}
            // if (!tmpl && tmpr || tmpl && !tmpr) return false;
            if (!tmpl || !tmpr) return false;	//situation of both empty has already been kicked
            if (tmpl->val != tmpr->val) {ltq.pop(); break;} //to make size different
            
            //应当注意到，对称树两个子树的层次遍历序列的关系：
            //如果以相反的顺序push左子和右子，就理应得到相同序列
            //与一般遍历不一样的地方在于空子位置也需要比对

            ltq.push(tmpl->left), ltq.push(tmpl->right);
            ltq.pop();
            
            rtq.push(tmpr->right), rtq.push(tmpr->left);
            rtq.pop();
        }
        if (ltq.size() == rtq.size()) return true;
        return false;
    }
};

//recursive version
class Solution {
    bool isMirror(TreeNode *l, TreeNode *r) {
        if (!l && !r) return true;
        if (!l || !r) return false;
        if (l->val != r->val) return false;
        return isMirror(l->left, r->right) && isMirror(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};