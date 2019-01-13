/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//没啥好说的，但是一开始做了很久
//因为第一次以为平衡树只有最后一层和倒数第二层才有叶子
//我也不知道我是怎么yy出来的规律，但是感觉总有人说过
//原来还是要按定义来
class Solution {
    int getDepth(TreeNode* root){
        if(!root) return 0;
        int lDepth = getDepth(root->left);
        int rDepth = getDepth(root->right);
        if(lDepth == -1 || rDepth == -1 || abs(lDepth - rDepth) > 1) return -1;
        return lDepth > rDepth ? 1 + lDepth : 1 + rDepth;
    }
public:
    bool isBalanced(TreeNode* root) {
        return getDepth(root) == -1 ? false : true;
    }
};