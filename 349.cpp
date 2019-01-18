class Solution {
    int next(int r, vector<int> &num) {
        int rtn = r + 1;
        while (rtn < num.size() && num[rtn] == num[r]) ++rtn;
        return rtn;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rtn;
        if (nums1.empty() || nums2.empty()) return rtn;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int r1 = 0, r2 = 0;
        while (true) {
            if (nums1[r1] > nums2[r2]) {
                while (r2 < nums2.size() && nums2[r2] < nums1[r1]) ++r2;
                if (r2 == nums2.size()) break;
                if (nums2[r2] == nums1[r1]) {
                    rtn.push_back(nums2[r2]);
                    r1 = next(r1, nums1);
                    r2 = next(r2, nums2);
                    if (r1 == nums1.size() || r2 == nums2.size()) break;
                }
            }
            else {
                while (r1 < nums1.size() && nums1[r1] < nums2[r2]) ++r1;
                if (r1 == nums1.size()) break;
                if (nums2[r2] == nums1[r1]) {
                    rtn.push_back(nums1[r1]);
                    r1 = next(r1, nums1);
                    r2 = next(r2, nums2);
                    if (r1 == nums1.size() || r2 == nums2.size()) break;
                }
            }
        }
        return rtn;
    }
};