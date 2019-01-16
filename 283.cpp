//虽然执行时间一样，但是显然我今天有点懵

//我的
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) return;
        int ins = 0, pion = 0;
        while (ins < nums.size() && nums[ins] != 0) {++ins, ++pion;}
        while (++pion < nums.size()) {
            while (pion < nums.size() && nums[pion] != 0) nums[ins++] = nums[pion++];
        }
        while (ins < nums.size()) nums[ins++] = 0;
    }
};

//别人的
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int t=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]){
               nums[t++] = nums[i]; 
            }
        }
        while(t<nums.size())
            nums[t++] = 0;
    }
};