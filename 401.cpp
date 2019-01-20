//这个就是完全按照了题目带起的节奏模拟的算法
//先产生比特位再验证时间
class Solution {
    string totime(const string &s) {
        string rtn;
        int tmp = 0;
        int power = 8;
        for (int i = 0; i < 4; ++i) {
            tmp += power * (s[i] - '0');
            power >>= 1;
        }
        if (tmp <= 11) {
            rtn += to_string(tmp);
        }
        else return string();
        rtn.push_back(':');
        tmp = 0;
        power = 32;
        for (int i = 4; i < 10; ++i) {
            tmp += power * (s[i] - '0');
            power >>= 1;
        }
        if (tmp <= 59) {
            if (tmp <= 9) rtn += '0';
            rtn += to_string(tmp);
        }
        else return string();
        return rtn;
    }
public:
    vector<string> readBinaryWatch(int num) {
        string s = "0000000000";    // 4+6=10 '0'
        string tmp;
        for (int i = 0; i < num; ++i) s[9 - i] = '1';
        vector<string> rtn;
        do {
            tmp = totime(s);
            if (!tmp.empty()) rtn.push_back(tmp);
        } while (next_permutation(s.begin(), s.end()));
        return rtn;
    }
};

//这个就是think out of the box
//先产生时间再验证比特位
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> rs;
        for (int h = 0; h < 12; h++)
            for (int m = 0; m < 60; m++)
                if (bitset<10> (h << 6 | m).count() == num)
                    rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
        return rs;
    }
};