class Solution {
public:
    // 1D compressed    |  Linear prefix	
    // Time: O(n)	    |  Space: O(1)	
    // Fibonacci-style  |  Initialize dp[0]=dp[1]=1
    // dp[i]=dp[i-1]+dp[i-2]
    // Bottom-up; i = 2→n (0→n). Top-down memo OK.
    // permutation type
    int climbStairs(int n) {
        int a=1, b=1;
        for(int i=2; i<=n; ++i){
            int c = a+b;
            a=b; b=c;
        }
        return b;
    }
};