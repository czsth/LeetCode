class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int curr = 1, profit = 0;
        for (; curr < prices.size(); ++curr) {
            if (prices[curr] > prices[curr - 1]) profit += prices[curr] - prices[curr - 1];
        }
        return profit;
    }
};