class Solution {
public:
    int titleToNumber(string s) {
        int rtn = 0;
        for (int r = 0; r < s.size(); ++r) {
            rtn = rtn * 26 + s[r] - 'A' + 1;
        }
        return rtn;
    }
};