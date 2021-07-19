//https://leetcode.com/problems/plus-one/
class Solution {
public:
    
    vector<int> plusOne(vector<int>& digits) {
        bool isFirstTime = true;
        int carry = 1;
        for(size_t i = digits.size(); i>0; i--) {
            printf("digits[%d] = %d\n", i-1, digits[i-1]);
            int inc = digits[i-1] + carry;
            carry = inc == 10;
            if(!carry) {
                digits[i-1] = inc;
                break;
            } else {
                if(i == 1) {
                    digits[i-1] = 1;  
                    digits.push_back(0);
                } else digits[i-1] = 0;
            }
        }
        return digits;
    }
};
