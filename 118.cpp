class Solution {
    // inline int getNum(vector<vector<int>> &v, )
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return vector<vector<int>>();
        vector<vector<int>> rtn{{1}};
        vector<int> tmp{1};
        for (int i = 1; i < numRows; ++i) {
            for (int j = 1; j < rtn[i - 1].size(); ++j) {
                tmp.push_back(rtn[i - 1][j - 1] + rtn[i - 1][j]);
            }
            tmp.push_back(1);
            rtn.push_back(tmp);
            tmp.resize(1);
        }
        return rtn;
    }
};