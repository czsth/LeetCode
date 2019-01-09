//brute force
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int minr = 0;
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i] < prices[minr]) minr = i;
            int maxr = i + 1;
            for (int j = i + 1; j < prices.size(); ++j) {
                if (prices[j] > prices[maxr]) maxr = j;
            }
            if (prices[maxr] - prices[minr] > profit) profit = prices[maxr] - prices[minr];
        }
        return profit;
    }
};

//dynamic
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int minr = 0;
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < prices[minr]) minr = i;
            else if (prices[i] - prices[minr] > profit)
                profit = prices[i] - prices[minr];
        }
        return profit;
    }
};