//这是邓俊辉在数据结构习题集里的代码
//以n的二进制位数r作为问题规模，该算法复杂度为O(log r)
//原因在于这是一个分治算法
#define POW(c) (1 << (c))
#define MASK(c) (((unsigned long) -1) / (POW(POW(c)) + 1))
#define ROUND(n, c) (((n) & MASK(c)) + ((n) >> POW(c) & MASK(c)))

class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = ROUND(n, 0);
        n = ROUND(n, 1);
        n = ROUND(n, 2);
        n = ROUND(n, 3);
        n = ROUND(n, 4);
        return n;
    }
};

//小技巧：每次直接去掉最后一个1
class Solution {
public:
	int hammingWeight(uint32_t n) {
        int ans=0;
        while(n)
        {
            ans++;
            n&=n-1;
        }
        return ans;
    }
};
