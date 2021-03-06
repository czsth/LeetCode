//对于这个题，我觉得能想到这里真的是神仙
//以下截取LeetCode国区用户“大吉”的评论：
/*
* 首先题目的意思是末尾有几个0
* 比如6! = 【1* 2* 3* 4* 5* 6】
* 其中只有2*5末尾才有0，所以就可以抛去其他数据 专门看2 5 以及其倍数 毕竟 4 * 25末尾也是0
* 比如10！ = 【2*4*5*6*8*10】
* 其中 4能拆成2*2  10能拆成2*5 
* 所以10！ = 【2*（2*2）*5*（2*3）*（2*2*2）*（2*5）】
* 一个2和一个5配对 就产生一个0 所以10！末尾2个0
* 转头一想 2肯定比5多 所以只数5的个数就行了
* 假若N=31 31里能凑10的5为[5, 2*5, 3*5, 4*5, 25, 6*5] 其中 25还能拆为 5**2 
* 所以 里面的5的个数为 int(31/(5**1)) +  int(31/(5**2))
* 所以 只要先找个一个 5**x < n 的x的最大数 然后按上面循环加起来
*/

//我又想了一会，我自己可以给出一个更细节的解释：
/*
给出的 n 一定可以写成 （5 * k + m) 的形式，
其中 m 是不大于 4 的整数
这里将 ans += n /= 5 就可以得到 n 中包含的 5 的个数
那么新的 n 作为商又可以写成 (5 * l + p) 的形式，
p 也是不大于 4 的整数
再除以 5 的商就是原来的 n 中包含的 25 的个数
依此类推
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n) ans += n /= 5;
        return ans;
    }
};