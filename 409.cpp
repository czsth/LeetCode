//偶数一定对称，奇数能出现一次在中间

class Solution {
public:
    int longestPalindrome(string s) {
        int barrel[256] = {0};
        bool oddExists = false;
        int rsl = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++barrel[s[i]];
        }
        for (int i = 0; i < 256; ++i) {
            if (!oddExists && barrel[i] % 2) {
                oddExists = true;
                ++rsl;
            }
            rsl += barrel[i] - (barrel[i] % 2);
        }
        return rsl;
    }
};