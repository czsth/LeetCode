//显然是一个等差数列求和的逆问题

class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(1+(long long)8*n)-1)/2;
    }
};

//这个版本快4 ms，仔细一看可以了解，因为加减比乘除快
class Solution {
public:
    int arrangeCoins(int n) {
        return int(sqrt((long long)2*n+0.25)-0.5);
    }
};

//这个版本更快了4 ms，但是不建议，因为好像据说long “至少和int一样长”
//所以可能在别的平台上就会崩
class Solution {
public:
    int arrangeCoins(int n) {
        return int(sqrt((long)2*n+0.25)-0.5);
    }
};