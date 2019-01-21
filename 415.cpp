class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int tmp;
        int i1 = num1.size() - 1, i2 = num2.size() - 1;
        string rsl;
        for (; i1 >= 0 || i2 >= 0; --i1, --i2) {
            tmp = 0;
            tmp += i1 >= 0 ? num1[i1] - '0' : 0;
            tmp += i2 >= 0 ? num2[i2] - '0' : 0;
            tmp += carry;
            carry = tmp / 10;
            tmp %= 10;
            rsl.push_back(tmp + '0');
        }
        if (carry) rsl.push_back(carry + '0');
        reverse(rsl.begin(), rsl.end());
        return rsl;
    }
};