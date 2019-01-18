class Solution {
public:
    bool isPerfectSquare(int num) {
        const int maxroot = 46340;
        if (num > maxroot * maxroot || num < 1) return false;
        int lo = 1, hi = maxroot;
        while (lo <= hi) {
            int mi = (lo + hi) >> 1;
            int misqr = mi * mi;
            if (misqr == num) return true;
            else if (misqr < num) lo = mi + 1;
            else hi = mi - 1;
        }
        return false;
    }
};