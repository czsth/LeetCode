class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        bool *primetest = new bool[n + 1];
        memset(primetest, true, (n + 1) * sizeof(bool));
        int limit = sqrt(n);
        for (int i = 2; i <= limit; ++i) {
            if (primetest[i]) {
                for (int j = i + i; j < n; j += i) primetest[j] = false;
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            if (primetest[i]) ++cnt;
        }
        delete []primetest;
        return cnt;
    }
};