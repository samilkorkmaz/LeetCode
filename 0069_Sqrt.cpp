//https://leetcode.com/problems/sqrtx/
class Solution {
public:
    //https://stackoverflow.com/questions/27958136/square-root-algorithm-c
    int mySqrt(int x) {
        if(x==1) return 1;
        double xHi = x;        
        double xLo = 0;
        double guess = (xHi+xLo)/2;
        while(abs(guess*guess - x) > 0.001) {
            //printf("guess = %1.3f, guess^2 = %1.1f\n", guess, guess*guess);
            if(guess*guess > x) xHi = guess;
            else xLo = guess;
            guess = (xHi+xLo)/2;
        }            
        //printf("final guess = %1.3f, guess^2 = %1.1f\n", guess, guess*guess);
        return (int) guess;
    }
};
