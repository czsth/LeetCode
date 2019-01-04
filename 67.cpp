class Solution {
public:
    string addBinary(string a, string b) {
        string big, small;
        if (a.size() > b.size()) big = a, small = b;
        else big = b, small = a;
        
        int ibig = big.size() - 1;
        int ismall = small.size() - 1;
        
        int carry = 0;
        
        int curr;

        //when shortter string hasn't finished
        for (; ismall >= 0; --ibig, --ismall) {
            curr = big[ibig] - '0' + small[ismall] + carry - '0';
            big[ibig] = (curr % 2) + '0';
            carry = curr / 2;
        }

        //deal with left string with carry
        for (; ibig >= 0; --ibig) {
            curr = big[ibig] - '0' + carry;
            big[ibig] = (curr % 2) + '0';
            carry = curr / 2;
        } 
        //note there may be another carry
        if (carry) big.insert(big.begin(), '1');
        return big;
    }
};