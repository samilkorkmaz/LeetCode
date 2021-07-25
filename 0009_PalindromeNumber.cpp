//https://leetcode.com/problems/palindrome-number/
class Solution {
public:
    int reverse(int x) {
        if (x==0) return 0;
        if (x <= INT_MIN) return 0;
        int nDigits = log10(abs(x))+1;
        printf("nDigits = %d\n", nDigits);
        int rx = 0;
        for(size_t i=0; i<nDigits; i++) {
            int lastDigit = x % 10;
            x /= 10;
            if (rx > INT_MAX/10 || (rx == INT_MAX / 10 && lastDigit > 7)) return 0;
            if (rx < INT_MIN/10 || (rx == INT_MIN / 10 && lastDigit < -8)) return 0;
            rx = rx * 10 + lastDigit;
        }
        return rx;
    }
    
    bool isPalindrome(int x) {
        if(x<0) return false; //negative numbers cannot be palindeomes
        //reverse integer and compare it with original
        int rx = reverse(x);
        return x == rx;        
    }
};
