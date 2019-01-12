//using map
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, char> stot;
        map<char, char> ttos;
        auto it_stot = stot.end();
        auto it_ttos = ttos.end();
        for (int i = 0; i < s.size(); ++i) {
            if ((it_stot = stot.find(s[i])) != stot.end()) {    //找到了t to s的映射
                if (it_stot->second != t[i]) {  //不是已经存在的映射
                    return false;
                }
            }
            else if ((it_ttos = ttos.find(t[i])) != ttos.end()) {   //t to s没有但是有s to t，说明不是一对一
                return false;
            }
            else {
                stot.insert(pair<char, char>(s[i], t[i]));
                ttos.insert(pair<char, char>(t[i], s[i]));
            }
        }
        return true;
    }
};

//use array as a specific, magical map
//faster
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int stot[256], ttos[256];
        memset(stot, 123, sizeof(stot));
        memset(ttos, 123, sizeof(ttos));
        for (int i = 0; i < s.size(); ++i) {
            if (stot[s[i]] < 256) {    //找到了t to s的映射
                if (stot[s[i]] != t[i]) {  //不是已经存在的映射
                    return false;
                }
            }
            else if (ttos[t[i]] < 256) {   //t to s没有但是有s to t，说明不是一对一
                return false;
            }
            else {
                stot[s[i]] = t[i], ttos[t[i]] = s[i];
            }
        }
        return true;
    }
};

//神仙代码
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; i++) {
            if (m1[s[i]] != m2[t[i]]) return false;
            //这里 i + 1 像一个“时间戳”
            //只有同时被赋值的两个才是存在对应关系的
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
