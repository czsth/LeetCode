//动态规划
//这个题COMPILE ERROR了，因为Ctrl+Enter居然是提交的快捷键
//我以为和Sublime一样是新增一行
//orz
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return vector<int>{1};
        vector<int> va{1, 1}, vb{1}, *last = &va, *curr = &vb;
        for (int i = 1; i < rowIndex; ++i) {
            for (int j = 1; j < last->size(); ++j) {
                curr->push_back((*last)[j - 1] + (*last)[j]);
            }
            curr->push_back(1);
            last->resize(1);
            swap(curr, last);
        }
        return *last;
    }
};