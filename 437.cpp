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
    //count指从此节点开始，得到任意长度路径和为target的个数
    void count(TreeNode *root, int sum, const int &target, int &cnt) {
        if (!root) return;
        sum += root->val;
        if (sum == target) ++cnt;
        count(root->left, sum, target, cnt);
        count(root->right, sum, target, cnt);
    }
    //对每一个节点使用count
    void traverse(TreeNode* root, const int &target, int &cnt) {
        if (!root) return;
        count(root, 0, target, cnt);
        traverse(root->left, target, cnt);
        traverse(root->right, target, cnt);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        int cnt = 0;
        traverse(root, sum, cnt);
        return cnt;
    }
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        
        if (root == nullptr)
            return 0;

        int res = 0;

        unordered_map<int, int> freq;
        freq[0] = 1;

        dfs(root, 0, freq, res, sum);

        return res;
    }

//8 ms，一个记忆化的方法
private:
    void dfs(TreeNode* node, 
             int pathSum, 
             unordered_map<int, int>& freq,
             int& res, 
             int sum)
    {
        pathSum += node->val;

        res += freq[pathSum - sum];

        ++freq[pathSum];

        if (node->left)
            dfs(node->left, pathSum, freq, res, sum);
        if (node->right)
            dfs(node->right, pathSum, freq, res, sum);

        --freq[pathSum];
    }
};