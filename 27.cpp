class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int curr = 0;
        for (; curr < nums.size() && nums[curr] != val; ++curr) {}
        if (curr >= nums.size()) return nums.size();
        
        int pion = curr;
        while (++pion < nums.size()) {
            if (nums[pion] == val) continue;
            else {
                nums[curr] = nums[pion];
                ++curr;
            }
        }
        return curr;
    }
};