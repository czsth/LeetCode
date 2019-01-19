class Solution {
public:
    char findTheDifference(string s, string t) {
        int barrel[256] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++barrel[t[i]];
            --barrel[s[i]];
        }
        ++barrel[t[t.size() - 1]];
        for (int i = 0; i < 256; ++i) {
            if (barrel[i]) return i;
        }
        return 0;
    }
};