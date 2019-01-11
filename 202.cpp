class Solution {
public:
    bool isHappy(int n) {
        //这里的4是个魔法，所有unHappy的数一定经过4
        //粗糙的证明如下：
        //设求各位平方和的操作为f(n), 则有f(n) <= 81([log(10)n] + 1)，
        //其中方括号表示向下取整。则可以知道满足条件的最大n为243，
        //也就是说任意大的整数在有限多次操作后必然进入[1, 243]的范围。
        //只需要找出其中不快乐数即可证明上述结论。
        //这里具体地在[1, 243]找不快乐数我想到可以开一个flag数组。
        while (n != 1 && n != 4) {
            int tmp = n;
            n = 0; 
            while (tmp) {
                int a = tmp % 10;
                if (a) n += a * a;
                tmp /= 10;
            }
        }
        if (n == 1) return true;
        else return false;
    }
};