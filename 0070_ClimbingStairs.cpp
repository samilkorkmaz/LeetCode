//https://leetcode.com/problems/climbing-stairs/
#include <iostream>

using namespace std;

int getWays(int n, int w[]) {
    //cout<<"n = " << n << ", w[n] = "<< w[n] <<endl;
    if(n <= 1) return 1;
    if(w[n] > 0) return w[n]; //return previously calculated result
    w[n] = getWays(n-1, w) + getWays(n-2, w);
    return w[n];
}

int climbStairsRecursive(int n) {
    int w[n+1];
    for(size_t i = 0; i<n+1; i++) w[i] = 0;
    return getWays(n, w);
}

int climbStairsIterative(int n) {
    int w[n+1];
    w[0] = 1; //only one way to reach step zero
    w[1] = 1; //only one way to reach step one 
    for(size_t i = 2; i < n+1; i++) {
        w[i] = w[i-1] + w[i-2];
    }
    return w[n];
}

int main()
{
    //int n = 1; //1 way
    //int n = 2; //1 way
    //int n = 3; //3 ways
    //int n = 4; //5 ways
    //int n = 5; //8 ways
    //int n = 6; //13 ways
    int n = 44;  //1134903170 ways
   
    cout << "stepsRecursive: "<< climbStairsRecursive(n) << endl;
    cout << "stepsIterative: "<< climbStairsIterative(n) << endl;

    return 0;
}
