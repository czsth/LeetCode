//此题即清华邓俊辉教授著C++版数据结构中，向量实现归并排序中，二路归并的一个变体

//12 ms，击败18.26%，因为只懂得从前往后赋值，不知变通
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merge;
        int i1 = 0, i2 = 0;
        while (i1< m && i2 < n) {
            if (nums1[i1] < nums2[i2]) merge.push_back(nums1[i1++]);
            else merge.push_back(nums2[i2++]);
        }
        if (i1 < m) while(i1 < m) merge.push_back(nums1[i1++]);
        else if (i2 < n) while(i2 < n) merge.push_back(nums2[i2++]);
        nums1 = merge;
    }
};

//执行用时为 4 ms 的范例，从后往前赋值
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.empty()) return;
        for(int i = m + n - 1;i >= 0;i--){
            if(m == 0||nums2[n-1] >= nums1[m-1]) 
            {
                nums1[i] = nums2[n-1];
                n--;}
            else {nums1[i] = nums1[m-1];
                 m--;}
            if(n == 0) break;
        }
    }
};

//最终实现, 4 ms
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //assume m, n are size of nums1, nums2 respectively
        int i = m + n;    //size of nums1
        while (--i > -1) {
            if (!n) break;
            if (!m || nums2[n - 1] >= nums1[m - 1]) nums1[i] = nums2[n-- - 1];
            else nums1[i] = nums1[m-- - 1];
        }
    }
};