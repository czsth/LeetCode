class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string str = to_string(x);
        int sz = str.size();
        for (int i = 0; i <= (sz-1) / 2; ++i) {
            if (str[i] != str[sz - i - 1]) return false;
        }
        return true;
    }
};