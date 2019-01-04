class Solution {
public:
    bool isValid(string s) {
        int table[7] = {93, 41, 0, 0, 0, 0, 125};
        stack<int> key_st;
        int key;
        for (int i = 0; i < s.size(); ++i) {
            key = s[i] % 13;    //hash function, specifically
            if (key != 2 && key != 8) {
                key_st.push(key);
            }
            else {
                if (key_st.empty() || s[i] != table[key_st.top()]) return false;
                else key_st.pop();
            }
        }
        if (key_st.empty()) return true;
        return false;
    }
};