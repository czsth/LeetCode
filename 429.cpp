/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> rsl;
        if (!root) return rsl;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> tmp;
            for (int i = 0; i < sz; ++i) {
                Node *curr = q.front();
                //update tmp
                tmp.push_back(curr->val);
                
                int chn = curr->children.size();
                if (chn) {
                    for (int j = 0; j < chn; ++j) {
                        //enqueue children
                        q.push(curr->children[j]);    
                    }
                }
                //dequeue this
                q.pop();
            }
            //push back tmp to rsl
            rsl.push_back(tmp);
        }
        return rsl;
    }
};

//其他写法
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> que;
        if(!root) return ans;
        que.push(root);
        while(!que.empty()){
            int k=que.size();
            ans.resize(ans.size()+1);
            for(int i=0;i<k;i++){
                ans[ans.size()-1].push_back(que.front()->val);
                //下面这个for是区间遍历的写法
                for(Node* node:que.front()->children) que.push(node);
                que.pop();
            }
        }
        return ans;
    }
};