class Solution {
    void split(vector<string> &v, string &src) {
        int from = 0, to = 0;
        while (true) {
            while (from < src.size() && !isalpha(src[from])) ++from;
            if (from == src.size()) return;
            to = from;
            while (to < src.size() && isalpha(src[to])) ++to;
            v.push_back(src.substr(from, to - from));
            from = to;
        }
    }
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        split(words, str);
        if (words.size() != pattern.size()) return false;
        map<char, string> ctos;
        map<string, char> stoc;
        for (int i = 0; i < pattern.size(); ++i) {
            if (!ctos.count(pattern[i])) {
                if (!stoc.count(words[i])) {
                    ctos[pattern[i]] = words[i];
                    stoc[words[i]] = pattern[i];
                }
                else return false;
            }
            else {
                if (ctos[pattern[i]] != words[i]) return false;
            }
        }
        return true;
    }
};