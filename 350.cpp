//呐其实这个和上一题是几乎一样的，代码也是我直接复制过来的
//只改了next函数

//虽然看起来很麻烦，可能是我封装得不好
//这是个O(nlogn + mlogm)的算法
//我暂时想不到再快了

class Solution {
    int next(int &r, vector<int> &num) {
        const int rr = r;
        int cnt = 0;
        while (r < num.size() && num[r] == num[rr]) ++cnt, ++r;
        return cnt;
    }
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
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
                    int tmp = nums2[r2];
                    int c1 = next(r1, nums1);
                    int c2 = next(r2, nums2);
                    int minc = min(c1, c2);
                    for (int i = 0; i < minc; ++i) rtn.push_back(tmp);
                    if (r1 == nums1.size() || r2 == nums2.size()) break;
                }
            }
            else {
                while (r1 < nums1.size() && nums1[r1] < nums2[r2]) ++r1;
                if (r1 == nums1.size()) break;
                if (nums2[r2] == nums1[r1]) {
                    int tmp = nums1[r1];
                    int c1 = next(r1, nums1);
                    int c2 = next(r2, nums2);
                    int minc = min(c1, c2);
                    for (int i = 0; i < minc; ++i) rtn.push_back(tmp);
                    if (r1 == nums1.size() || r2 == nums2.size()) break;
                }
            }
        }
        return rtn;
    }
};