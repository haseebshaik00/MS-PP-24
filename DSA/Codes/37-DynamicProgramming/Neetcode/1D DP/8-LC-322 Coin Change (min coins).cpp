// 1D	Unbounded knapsack over amount	
    // O(n·A)	O(A) + O(n log n)	 |         dp[x]=min(dp[x], dp[x-c]+1)	
    // Order doesn't matter | amount outer & increasing	(preferred)
    // Bottom-up
    int coinChange(vector<int>& coins, int amount) {
        const int INF = amount + 1;
        vector<int> dp(amount+1, INF);
        dp[0] = 0; sort(coins.begin(), coins.end());
        for(int i=1; i<=amount; ++i){
            for(auto &x: coins){
                if(i < x) break;
                dp[i] = min(dp[i], dp[i-x] + 1);
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }