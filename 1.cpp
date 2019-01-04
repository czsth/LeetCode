class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rsl;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) { rsl.push_back(i); rsl.push_back(j); return rsl;}
            }
        }
        return rsl;
    }
};