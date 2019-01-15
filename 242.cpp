class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int barrel[256] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++barrel[s[i]];
            --barrel[t[i]];
        }
        for (int i = 0; i < 256; ++i) {
            if (barrel[i]) return false;
        }
        return true;
    }
};