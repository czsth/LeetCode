//greed algorithm
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int small = 0, big = numbers.size() - 1;
        //set bigger
        while (true) {
            while (numbers[small] + numbers[big] > target) --big;
            if (numbers[small] + numbers[big] == target) break;
            while (numbers[small] + numbers[big] < target) ++small;
            if (numbers[small] + numbers[big] == target) break;
        }
        return vector<int>{++small, ++big};
    }
};
