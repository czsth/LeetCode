/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//first try, wanted to solve by bfs
//hacked by sample: [1,2,null,3,null,4,null,5]
//which is a single branch
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (root->left && !root->left->left && !root->left->right || 
            root->right && !root->right->left && !root->right->right)
            return 2;
        int cnt = 0;
        queue<TreeNode *> q;
        q.push(root);
        bool ground = false;
        while (!q.empty()) {
            //per level
            ++cnt;
            bool nonNull = false;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                if (q.front()) nonNull = true;
                if (!q.front()) {
                    ground = true;
                    q.pop();
                    continue;
                }
                q.push(q.front()->left), q.push(q.front()->right);
                q.pop();
            }
            if (ground && nonNull) return cnt;
            else if (ground) return --cnt;
        }
        return --cnt;
    }
};

//so it seems to be a dfs question
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int left = minDepth(root->left), right = minDepth(root->right);
        return (left && right) ? 1 + min(left,right) : 1 + left + right;
    }
};