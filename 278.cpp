//经典的二分查找

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // if (isBadVersion(1)) return 1;
        // if (!isBadVersion(n - 1)) return n;
        int lo = 1, hi = n, mi;
        bool curr, aside;
        while (true) {
            mi = ((long long)lo + hi) / 2;
            curr = isBadVersion(mi);
            if (curr) {
                if (mi == 1) return 1;
                aside = isBadVersion(mi - 1);
            }
            else {
                if (mi == n - 1) return n;
                aside = isBadVersion(mi + 1);
            }
            if (curr != aside) return curr ? mi : mi + 1;
            
            if (curr) hi = mi - 1;
            else lo = mi + 1;
        }
    }
};