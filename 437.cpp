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

// 记忆搜索，主要思想：记录深度搜索时——从根节点往下的累积和（记为当前和cur），并每次将cur出现次数+1。

// （stl map key如果不存在会自动初始化为0）。
// 下次使用m[cur-sum]如果为一个非0值，则说明从当前节点往上追溯（不一定追溯到根节点）可能存在一个或多个符合的路径。

// （比如，假设目标和为8，假设当前节点为x，假设有路径4->4和4->4->1->-1->x则都符合）。
class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
	    unordered_map<int, int> m;//memory
	    m[0] = 1;//cur - sum = 0, return 1
	    return dfs(root, sum, 0, m);
	}
	int dfs(TreeNode* node, int sum, int cur, unordered_map<int, int>& m) {
	    if (!node) return 0;
	    cur += node->val;	//curr是从根节点到当前节点的路径长度和
	    int ans = m[cur - sum];
	    ++m[cur];
	    ans += dfs(node->left, sum, cur, m) + dfs(node->right, sum, cur, m);
	    --m[cur];
	    return ans;
	}
};

//同样思想的另一种写法，区别在于下面这种使用引用来修改答案值
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        
        if (root == nullptr) return 0;
        int res = 0;

        unordered_map<int, int> freq;
        freq[0] = 1;

        dfs(root, 0, freq, res, sum);

        return res;
    }

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
        if (node->left) dfs(node->left, pathSum, freq, res, sum);
        if (node->right) dfs(node->right, pathSum, freq, res, sum);
        --freq[pathSum];
    }
};