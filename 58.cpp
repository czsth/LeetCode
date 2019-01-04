class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int last = s.size() - 1;
        while (last >= 0 && s[last] == ' ') --last;
        int r = last;
        while (r >= 0 && s[r] != ' ') --r;
        return last - r;
    }
};