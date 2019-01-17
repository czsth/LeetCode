class Solution {
public:
    bool isPowerOfFour(int num) {
    	if (num <= 0) return false;
    	while (num != 1 && !(num % 4)) {
    		num /= 4;
    	}
		if (num == 1) return true;
    	return false;
    }
};