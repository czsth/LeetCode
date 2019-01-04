class Solution {
public:
    string countAndSay(int n) {
        string news = "1", olds = "1";
        char curr;
        int cnt = 0;
        while (--n) {
            olds = news;
            news.clear();
            for (int i = 0; i < olds.size(); ) {
                cnt = 0;
                curr = olds[i];
                while ((i + ++cnt) < olds.size() && olds[i + cnt] == curr) {}
                news += ('0' + cnt);
                news += curr;
                i += cnt;
            }
        }
        return news;
    }
};