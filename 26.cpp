//version of iterator, 24 ms in 161 test
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        int cnt = 1;
        auto curr = nums.begin(), pion = curr;
        while (++pion != nums.end()) {
            if (*pion != *curr) {
                *++curr = *pion;
                ++cnt;
            }
        }
        return cnt;
    }
};

//without iterator, 20 ms in 161 test
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        int cnt = 1;
        int curr = 0, pion = 0;
        int sz = nums.size();
        while (++pion != sz) {
            if (nums[pion] != nums[curr]) {
                nums[++curr] = nums[pion];
                ++cnt;
            }
        }
        return cnt;
    }
};