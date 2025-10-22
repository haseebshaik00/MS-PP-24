class Solution {
public:
    // 1D compressed    |  Linear prefix (weighted)	
    // Time: O(n)	    |  Space: O(1)	
    // dp[i]=min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])	
    // Start cost-free at 0/1; answer dp[n].
    // Bottom-up; i = 2→n (0→n).
    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size(), prev1=0, prev2=0;
       for(int i=2; i<=n; ++i){
            int curr = min(prev1 + cost[i-1], prev2 + cost[i-2]);
            prev2 = prev1;
            prev1 = curr;
       }
    }
};
