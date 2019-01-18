// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mi = ((long long)lo + hi) >> 1;
            int rsl = guess(mi);
            if (!rsl) return mi;
            else if (rsl > 0) lo = mi + 1;
            else hi = mi - 1;
        }
        return 0;
    }
};