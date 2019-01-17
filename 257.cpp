//for given binary tree return all route to leaves
//only modify string when visiting node
//add "<val>->"
//resize s when adding to vector to uniform

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
	void dfs(TreeNode *pnode, vector<string> &v, string s) {
		if (!pnode) return;
		s = s + to_string(pnode->val) + "->";
		if (!pnode->left && !pnode->right) {
			s.resize(s.size() - 2);
			v.push_back(s);
			return;
		}
		dfs(pnode->left, v, s);
		dfs(pnode->right, v, s);
	}

public:
    vector<string> binaryTreePaths(TreeNode* root) {
    	vector<string> v;
    	dfs(root, v, "");
    	return v;
    }
};


//it's a waste of space to use a string object in function dfs
//try to make space complexity O(1)
class Solution {
	//dfs state code: 0->string unmodified, 1->string modified
	void dfs(TreeNode *pnode, vector<string> &v, string &s) {
		s = s + to_string(pnode->val) + "->";
		if (!pnode->left && !pnode->right) {
			s.resize(s.size() - 2);
			v.push_back(s);
            s += "->";
			return;
		}
        int cnt;
        //go left
        if (pnode->left) {
            dfs(pnode->left, v, s);
            cnt = 0;
            while (isdigit(s[s.size() - 3 - cnt])) ++cnt;
            if (s[s.size() - 3 - cnt] == '-') ++cnt;
            s.resize(s.size() - cnt - 2);
        }
        
        //go right
        if (pnode->right) {
            dfs(pnode->right, v, s);
            cnt = 0;
            while (isdigit(s[s.size() - 3 - cnt])) ++cnt;
            if (s[s.size() - 3 - cnt] == '-') ++cnt;
            s.resize(s.size() - cnt - 2);
        }
	}

public:
    vector<string> binaryTreePaths(TreeNode* root) {
    	vector<string> v;
        if (!root) return v;
    	string s;
    	dfs(root, v, s);
    	return v;
    }
};