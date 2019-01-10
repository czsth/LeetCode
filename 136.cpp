class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.count(nums[i])) s.erase(nums[i]);
            else s.insert(nums[i]);
        }
        return *s.begin();
    }
};

//really smart version
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int rtn = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            rtn ^= nums[i];
        }
        return rtn;
    }
};