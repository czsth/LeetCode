class Solution {
    inline bool match(string &s, int curr, string &mode) {
        for (int i = 0; i < mode.size(); ++i) {
            if (s[curr + i] != mode[i]) return false;
        }
        return true;
    }
public:
    int romanToInt(string s) {
        //我还尝试了将string换成char*，结果并没有变快，可见string的创建速度是可以的
        string cmp[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int resp[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int curr_max_rk = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); ) {
            if (match(s, i, cmp[curr_max_rk])) {
                ans += resp[curr_max_rk];
                i += cmp[curr_max_rk].size();
            }
            else ++curr_max_rk;
        }
        return ans;
    }
};