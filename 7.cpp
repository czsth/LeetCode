class Solution {
public:
    int reverse(int x) {
        long long xx = x;
        int sgn = xx < 0 ? -1 : 1;
        xx *= sgn;
        long long ans = xx % 10;
        while (xx /= 10) {
            ans = ans * 10 + xx % 10;
        }
        if (ans > 2147483647) return 0;
        return ans * sgn;
    }
};