class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2 || k < 1) return false;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size() && j <= i + k; ++j) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); ++i){
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) return true;
            else m[nums[i]]=i;
        }
        return false;
    }
};

//剩下运行时间更短的都是魔法师
