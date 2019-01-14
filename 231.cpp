// (n & (n-1)) 可以去掉n的二进制表示中最后一个1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && !((n - 1) & n);
    }
};