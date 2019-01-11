//使用递归方法解决会超时
//道理同使用递归求解斐波那契数列，会访问重复节点
class Solution {
    int maxRob(vector<int> &nums, int r) {
        if (r >= nums.size()) return 0;
        return nums[r] + max(maxRob(nums, r + 2), maxRob(nums, r + 3));
    }
public:
    int rob(vector<int>& nums) {
        return max(maxRob(nums, 0), maxRob(nums, 1));
    }
};

//应该使用动态规划
class Solution {
public:
    int rob(vector<int>& nums) {
        int dy[4] = {0};    //装着当前元素前三个元素对应的、到该元素所能劫到最大金额
        //这里将动态存储数组初始化为0，统一了nums.size() <= 3等的所有情况，应用了“哨兵”思想
        for (int i = 0; i < nums.size(); ++i) {
            //count max
            dy[3] = nums[i] + max(dy[0], dy[1]);
            //move
            //此处其实可以使用类似 i % 4 的手法免去三次赋值，不过意义不大，不再赘述
            dy[0] = dy[1];
            dy[1] = dy[2];
            dy[2] = dy[3];
        }
        return max(dy[1], dy[2]);
    }
};
