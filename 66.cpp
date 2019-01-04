class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size();
        bool carry = (digits[sz - 1] += 1) / 10;
        digits[sz - 1] %= 10;
        for (int i = sz - 2; i >= 0; --i) {
            if (carry) {
                carry = ++digits[i] / 10;
                digits[i] %= 10;
            }
            else return digits;
        }
        if (!carry) return digits;
        
        digits.push_back(digits[sz - 1]);   //note that here size = sz + 1
        for (int i = sz - 1; i > 0; --i) {
            digits[i] = digits[i - 1];
        }
        digits[0] = 1;
        return digits;
    }
};