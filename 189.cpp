class Solution {
    inline void swap(vector<int> &v, int lo, int hi) {
        v[lo] ^= v[hi] ^= v[lo] ^= v[hi];
    }
    
    void rev(vector<int> &v, int lo, int hi) {
        while (lo < hi) swap(v, lo++, hi--);
    }
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k %= nums.size();
        if (!k) return;
        rev(nums, 0, nums.size() - k - 1), rev(nums, nums.size() - k, nums.size() - 1);
        rev(nums, 0, nums.size() - 1);
    }
};