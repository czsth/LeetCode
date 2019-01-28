static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
    bool isRepeated(string &s, int start, const int& len) {
        if (start >= s.size()) return true;
        for (int i = 0; i < len; ++i) {
            if (s[start + i] != s[i]) return false;
        }
        return isRepeated(s, start + len, len);
    }
public:
    bool repeatedSubstringPattern(string s) {
        int start = 1;
        // when substring has a shortter length than s
        while (true) {
            // find next
            while (start <= (s.size() / 2) && (s.size() % start || s[start] != s[0])) ++start;
            if (start > s.size() / 2) break;
            
            if (isRepeated(s, start, start)) return true;
            else ++start;
        }
        return false;
    }
};

// 周期串的自匹配性
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s+s;
        string ss_(ss.begin()+1,ss.end()-1);
        return ss_.find(s)<ss_.size();
    }
};