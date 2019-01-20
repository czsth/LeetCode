class Solution {
public:
    int findNthDigit(int n) {
        long long digs = 1, range = 9;
        while (n - digs * range > 0) {
            n -= digs * range;
            ++digs;
            range *= 10;
        }
        //此时digs就是位数，--n是相对digs位最小数的偏移量
        int rm = (--n) % digs;
        int last = pow(10, digs - 1) + n / digs;
        return to_string(last)[rm] - '0';
    }
};