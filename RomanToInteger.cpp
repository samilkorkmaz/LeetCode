//https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    bool contains(string s, string sub, size_t pos = 0) {
        return s.find(sub, pos) != std::string::npos;
    }
    
    int count(string s, char c, char specialChar='a') {
        int cnt = 0;
        int posSpecialChar = pos(s, specialChar);
        for(size_t i=0; i < s.size(); i++) {
            if (s[i] == c) {
                if (i < posSpecialChar) cnt++; //example: do not count X two times in XIX
            }    
        }
        //printf("cnt = %d\n", cnt);
        return cnt;
    }
    
    int pos(string s, char c, size_t start = 0) {
        int p = -1;
        for(size_t i=start; i < s.size(); i++) {
            if (s[i] == c) {
                p = i;
                break;
            } 
        }
        return p;
    }
    
    int romanToInt(string s) {
        if(0 == s.compare("III")) return 3;
        int ones=0;
        int tens = 0;
        int hundreds = 0;
        int thousands = 0;
        
        if (contains(s, "IV")) {
            ones = 4;
        } else if (contains(s, "IX")) {
            ones = 9;
            printf("here ones = %d\n", ones);
        } else {//1,2,3,5,6,7,8
            if (contains(s, "V")) ones += 5;
            ones += count(s, 'I');
        }
        
        if (contains(s, "XL")) {
            tens = 40;
        } else if (contains(s, "XC")) {
            tens = 90;
        } else {//10,20,30,50,60,70,80
            if (contains(s, "L")) tens += 50;            
            tens += 10*count(s, 'X', 'I');
        }
        
        if (contains(s, "CD")) {
            hundreds = 400;
        } else if (contains(s, "CM")) {
            hundreds = 900;
        } else {//100,200,300,500,600,700,800
            if (contains(s, "D")) hundreds += 500;
            hundreds += 100*count(s, 'C', 'X');
        }
        //printf("pos(M) = %d, cM = %d\n", pos(s, 'M'), count(s, 'M', 'C'));
        thousands += 1000*count(s, 'M', 'C');
        
        return ones + tens + hundreds + thousands;
    }
};
