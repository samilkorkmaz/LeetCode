//https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    
int getWays(int n, int w[]) {
    //cout<<"n = " << n << ", w[n] = "<< w[n] <<endl;
    if(n <= 1) return 1;
    if(w[n] > 0) return w[n]; //return previously calculated result
    w[n] = getWays(n-1, w) + getWays(n-2, w);
    return w[n];
}

int climbStairs(int n) {
    int w[n+1];
    for(size_t i = 0; i<n+1; i++) w[i] = 0;
    return getWays(n, w);
}

};
