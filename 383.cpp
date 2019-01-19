class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() < ransomNote.size()) return false;
        int barrel[26] = {0};
        for (int i = 0, j = 0; i < ransomNote.size() || j < magazine.size(); ++i, ++j) {
            if (i < ransomNote.size()) --barrel[ransomNote[i] - 'a'];
            if (j < magazine.size()) ++barrel[magazine[j] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (barrel[i] < 0) return false;
        }
        return true;
    }
};