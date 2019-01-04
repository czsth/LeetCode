class Solution {
public:
    int climbStairs(int n) {
        //it is almost a Fibonacci sequence
        //for any staircase with n step, A_n = A_{n-1}(walk one step) + A_{n-2}(walk two step)
        int a = 0, b = 1;
        while (n--) {
            b += a, a = b - a;
        }
        return b;
    }
};