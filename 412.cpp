class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> rsl;
        for (int i = 1; i <= n; ++i) {
            if (!(i % 3) && !(i % 5)) rsl.push_back("FizzBuzz");
            else if (!(i % 3)) rsl.push_back("Fizz");
            else if (!(i % 5)) rsl.push_back("Buzz");
            else rsl.push_back(to_string(i));
        }
        return rsl;
    }
};