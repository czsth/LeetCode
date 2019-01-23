//这个竟然很慢，可能是memset这种拖累的
//我以为alien的处理很机智，实际上可能是个debuff
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return vector<int>();
        
        int *pat = new int[26]{0};  //模式串计数
        for (int i = 0; i < p.size(); ++i) ++pat[p[i] - 'a'];   //初始化模式串计数
        
        int *tmp = new int[26]{0};  //临时计数
        
        vector<int> rsl;
        bool foundAlien;    //出现模式串中不存在的字符
        
        for (int i = 0; i < s.size() - p.size() + 1;) {
            memset(tmp, 0, 26 * sizeof(int));       //初始化临时计数
            foundAlien = false;
            for (int j = 0; j < p.size(); ++j) {
                if (!pat[s[i + j] - 'a']) {   //找到不存在与模式串中的字符
                    foundAlien = true;
                    i = i + j + 1;      //匹配串从不存在字符的下一个位置开始寻找
                    break;              //退出此次寻找
                }
                ++tmp[s[i + j] - 'a'];
            }
            if (!foundAlien) {
                //验证临时计数与模式计数
                int j;
                for (j = 0; j < 26; ++j) {
                    if (tmp[j] != pat[j]) break;
                }
                if (j == 26) rsl.push_back(i);
                ++i;
            }
        }
        delete []tmp;
        delete []pat;
        return rsl;
    }
};

//上面的280 ms，这个竟然28 ms
//仔细一想，其实并没有什么竟然
//上面最坏情况：没有alien，此时时间复杂度为O(mn)，其中m、n分别为字符串s、p的长度
//下面平均情况：从头走到尾：O(256 * m) = O(m)
//快🌶么多也是很正常！！
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.empty()){
            return {};
        }
        vector<int> res;
        vector<int> hash1(256,0),hash2(256,0);
        
        for(int i=0;i<p.length();i++){
            hash1[p[i]]++;
            hash2[s[i]]++;
        }
        if(hash1==hash2) res.push_back(0);
        for(int i=p.length();i<s.length();i++){
            //这里的策略是像一个定长队列，同时入队和出队
            hash2[s[i]]++;
            hash2[s[i-p.length()]]--;
            if(hash1==hash2){
                res.push_back(i-p.length()+1);
            }
        }
        return res;
    }
};

//再优化一点点，快了4 ms
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return vector<int>();       //这里
        
        vector<int> res;
        vector<int> hash1(26,0),hash2(26,0);                //size变成26，因为保证是小写字母
        
        for(int i=0;i<p.length();i++){
            hash1[p[i] - 'a']++;
            hash2[s[i] - 'a']++;
        }
        if(hash1==hash2) res.push_back(0);
        for(int i=p.length();i<s.length();i++){
            //这里的策略是像一个定长队列，同时入队和出队
            hash2[s[i] - 'a']++;
            hash2[s[i-p.length()] - 'a']--;
            if(hash1==hash2){
                res.push_back(i-p.length()+1);
            }
        }
        return res;
    }
};