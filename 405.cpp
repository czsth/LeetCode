class Solution {
    char tochar(int rm) {
        if (rm < 10) return rm + '0';
        return rm - 10 + 'a';
    }
public:
    string toHex(int num) {
        if (!num) return string("0");
        int rm;
        unsigned unum = num;
        string s;
        while (unum != 0) {
            rm = unum & 0b1111;
            unum >>= 4;
            s.push_back(tochar(rm));
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

//有人这样做tochar更聪明一分
string map = "0123456789abcdef";
return map[unum % 16];