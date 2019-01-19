class Solution {
public:
    int firstUniqChar(string s) {
        int barrel[256] = {0};
        for (int i = 0; i < s.size(); ++i) ++barrel[s[i]];
        for (int i = 0; i < s.size(); ++i) {
            if (barrel[s[i]] == 1) return i;
        }
        return -1;
    }
};