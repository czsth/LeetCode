class Solution {
public:
    int compress(vector<char>& chars) {
        int ins = -1, pion = 0;
        string tmp;
        int cnt = 0;
        while (pion < chars.size()) {
            char curr = chars[pion];
            chars[++ins] = curr;
            cnt = 0;
            while (pion < chars.size() && chars[pion] == curr) ++pion, ++cnt;
            if (cnt != 1) {
                tmp = to_string(cnt);       //这里没有达到就地算法的要求，改起来也不难，稍微麻烦一点
                for (int i = 0; i < tmp.size(); ++i) {
                    chars[++ins] = tmp[i];
                }
            }
        }
        //chars.resize(ins + 1);    //这一行就慢了4 ms
        return ins + 1;
    }
};