class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n > 0) {
        	//注意这里的 --n
        	//因为每一位范围是 [1, 26]
        	//计算对应字符时减一取模，恰好可以映射到 'A'+[0, 25]
        	//最后除以26又恰好可以“左移”一位（26进制地）
            s += ('A' + (--n % 26));
            n /= 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};