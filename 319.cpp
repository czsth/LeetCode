class Solution {
public:
    int bulbSwitch(int n) {
        // int *bulbs = new int[n];
        // for (int i = 0; i < n; ++i) bulbs[i] = 0;
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = i - 1; j < n; j += i) {
        //         bulbs[j] = !bulbs[j];
        //     }
        // }
        // int cnt = 0;
        // for (int i = 0; i < n; ++i) {
        //     if (bulbs[i]) ++cnt;
        // }
        // delete []bulbs;
        // return cnt;
        return sqrt(n);
    }
};