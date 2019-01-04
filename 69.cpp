class Solution {
public:
    int mySqrt(int x) {
        unsigned long long lo = 0, hi = x, mi;
        while (hi - lo > 1) {
            mi = (lo + hi) / 2;
            if (mi * mi > x) hi = mi;
            else if (mi * mi < x) lo = mi;
            else return mi;
        }
        return hi * hi > x ? lo : hi;
    }
};