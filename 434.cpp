//一开始没看清“单词”的定义，用了isalpha()
//委婉地说，我觉得这不是好题
class Solution {
    int w(const string &s, int i) {
        while (i < s.size() && s[i] != ' ') ++i;
        while (i < s.size() && s[i] == ' ') ++i;
        return i;
    }
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        int i = 0, cnt = 0;
        if (s[0] != ' ') ++cnt;
        while ((i = w(s, i)) < s.size()) ++cnt;
        return cnt;
    }
};