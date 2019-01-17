class Solution {
    inline bool isVowel(char c) {
        switch(c) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                return true;
            default:
                return false;
        }
    }
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (true) {
            while (!isVowel(s[l])) {++l;}
            while (!isVowel(s[r])) {--r;}
            if (l >= r) break;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};