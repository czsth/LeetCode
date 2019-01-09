class Solution {
    int nextAlnum(int front, int back, string &s) {
        while (!isalnum(s[++front]) && front != back) {}
        return front;
    }
    int lastAlnum(int back, int front, string &s) {
        while (!isalnum(s[--back]) && front != back) {}
        return back;
    }
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        int front = nextAlnum(-1, s.size() - 1, s), back = lastAlnum(s.size(), 0, s);
        for (; front < back; front = nextAlnum(front, back, s), back = lastAlnum(back, front, s)) {
            if (s[front] != s[back]) {
                if (isdigit(s[front])) return false;
                if (tolower(s[front]) != tolower(s[back])) return false;
            }
        }
        return true;
    }
};