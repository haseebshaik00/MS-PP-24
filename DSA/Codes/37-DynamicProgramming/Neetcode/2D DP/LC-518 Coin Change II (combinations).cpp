class Solution {
public:
    // This is combination type
    // try permutation type - LC 377
    // 1D	Unbounded knapsack (count)	
    // O(n·A)	O(A)	dp[x]+=dp[x-c]	
    // Coins outer, amount forward (avoid permutations).	
    // Bottom-up; for coin: x = c→A (forward).
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0); dp[0] = 1;
        for(auto &x: coins){
            for(int a=x; a<=amount; ++a){
                if(INT_MAX-dp[a]-dp[a-x] > 0) dp[a] += dp[a-x];
                else dp[a] = INT_MAX;
            }
        }
        return dp[amount];
    }
};