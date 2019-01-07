//注意到二分查找算法的判定树是一棵平衡树
class Solution {
    //这里的区间是[lo, hi)
    void makeTree(vector<int> &nums, int lo, int hi, TreeNode *root) {
        int mi;
        root->val = nums[mi = (hi + lo) / 2];
        if (hi - lo == 1) return;
        if ((mi - lo) > 0) makeTree(nums, lo, mi, root->left = new TreeNode(0));
        if ((hi - mi - 1) > 0) makeTree(nums, mi + 1, hi, root->right = new TreeNode(0));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        TreeNode *root = new TreeNode(0);
        makeTree(nums, 0, nums.size(), root);
        return root;
    }
};

//更为易读的版本
class Solution {
    //这里的区间是[lo, hi]
    TreeNode* vectoBST(vector<int>& nums , int lo , int hi){
        if(lo > hi) return NULL;
        else {
            int mi = (lo + hi) / 2;
            TreeNode *cur = new TreeNode(nums[mi]); 
            cur->left = vectoBST(nums, lo, mi - 1); 
            cur->right = vectoBST(nums, mi + 1, hi);
            return cur;
        }
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return vectoBST(nums, 0, (int)nums.size() - 1);
    }
};