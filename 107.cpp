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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> rtn;
        if (!root) return rtn;
        rtn.push_back(vector<int> {root->val});
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *pnode;
        while (!q.empty()) {
            vector<int> tmp;
            //the first time i use the size of a queue
            //maybe i'm really kind of smart
            int currSize = q.size();    
            for (int i = 0; i < currSize; ++i) {
                pnode = q.front();
                if (pnode->left)  q.push(pnode->left),  tmp.push_back(pnode->left->val);
                if (pnode->right) q.push(pnode->right), tmp.push_back(pnode->right->val);
                q.pop();    
            }
            if (!tmp.empty()) rtn.push_back(tmp);
        }
        reverse(rtn.begin(), rtn.end());
        return rtn;
    }
};