//这也WA了两下
//我觉得我真的有点粗心
//接下来做题要认真验证
//不要瞎提交
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        while (num) {
            if (num == 1) {return true;}
            else if (!(num % 2)) {num /= 2;}
            else if (!(num % 3)) {num /= 3;}
            else if (!(num % 5)) {num /= 5;}
            else {return false;}
        }
        return true;
    }
};