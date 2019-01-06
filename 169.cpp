//my solution, original meaning of majority number
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<vector<int>> maxcnt;
        for (int i = 0; i < nums.size(); ++i) {
            int j = 0;
            for (j = 0; j < maxcnt.size(); ++j) {
                if (maxcnt[j][0] == nums[i]) break;
            }
            if (j != maxcnt.size()) ++maxcnt[j][1];
            else maxcnt.push_back(vector<int>{nums[i], 1});
        }
        int maxr = 0;
        for (int i = 1; i < maxcnt.size(); ++i) {
            if (maxcnt[i][1] > maxcnt[maxr][1]) maxr = i;
        }
        return maxcnt[maxr][0];
    }
};

//sample of 8 ms
//actually this question defined a new kind of "majority number":
//who appears more then ⌊n/2⌋
//so, mathmatically, it can be written as:
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = nums[0],temp = 0;
        for(auto a:nums){
            if(a==ret)
                temp++;
            else
                temp--;
            if(temp<=0){
                ret = a;
                temp = 1;
            }
        }
        return ret;
    }
};