class Solution {
public:
    // 1D	0/1 knapsack (subset sum)	
    // O(n·S)	O(S)	dp[w]= dp[w-num]	
    // Target S=sum/2; loop capacity backward.	
    // Bottom-up; for num: w = S→num (backward).
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return false;
        sum = sum/2;
        vector<bool> dp(sum+1, false); dp[0] = true;
        for(auto &x: nums){
            for(int i=sum; i>=x; --i){
                dp[i] = dp[i] || dp[i-x];
                if(dp[sum]) return true;
            }
        }
        return dp[sum];
    }
};