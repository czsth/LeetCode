class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.size() < needle.size()) return -1;
        int maxi = haystack.size() - needle.size() + 1;
        for (int i = 0; i < maxi; ++i) {
            if (haystack[i] == needle[0]) {
                int j;
                for (j = 1; j < needle.size(); ++j) {
                    if (haystack[i + j] != needle[j]) break;
                }
                if (j == needle.size()) return i;
            }
        }
        return -1;
    }
};