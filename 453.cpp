class Solution {
public:
    /*
    用户std=c++11的笔记：
    每次移动让剩余的n-1个数加1，
    相当于每次移动让选定的那个数减1，
    所以最少移动次数其实就是所有元素减去最小元素的和
    */
    int minMoves(vector<int>& nums) {
        int min = nums[0], tot = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < min) min = nums[i];
            tot += nums[i];
        }
        return tot - min * nums.size();
    }
};