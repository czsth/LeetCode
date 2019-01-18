class Solution {
public:
    int getSum(int a, int b) {
        int rsl = a ^ b;
        int carry = (a & b) << 1;
        while (carry) {
            int tmprsl = rsl ^ carry;
            carry = (carry & rsl) << 1;
            rsl = tmprsl;
        }
        return rsl;
    }
};