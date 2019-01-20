//利用哨兵的思想统一nextMax函数
class Solution {
    int nextMax(int oldMax, vector<int> &nums) {
        bool foundFirst = false;
        int max;
        for (int i = 0; i < nums.size(); ++i) {
            if (!foundFirst && nums[i] < oldMax) {
                foundFirst = true;
                max = nums[i];
            }
            else if (nums[i] > max && nums[i] < oldMax) max = nums[i];
        }
        return foundFirst ? max : oldMax;
    }
public:
    int thirdMax(vector<int>& nums) {
        int first = nextMax(2147483647, nums);
        int second = nextMax(first, nums);
        if (second == first) return first;
        int third = nextMax(second, nums);
        return second == third ? first : third;
    }
};