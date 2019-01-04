class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string();
        string ans;
        char curr;
        int rk = 0;
        bool flag = true;
        while (true) {
            if (rk >= strs[0].size()) break;
            curr = strs[0][rk];
            for (int i = 1; i < strs.size(); ++i) {
                if (rk >= strs[i].size() || strs[i][rk] != curr) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
            ans += curr;
            ++rk;   //length increase
        }
        return ans;
    }
};