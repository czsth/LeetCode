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

//another version by someone else
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        vector<int> v;
        TreeNode* p = NULL;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){ 
            p = q.front();q.pop();
            if(p){
                v.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            else {
                //use NULL as a flag, together with size of queue
                //to figure out when the level ends
                if(q.size() > 0) q.push(NULL);
                res.push_back(v);
                v.resize(0);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
