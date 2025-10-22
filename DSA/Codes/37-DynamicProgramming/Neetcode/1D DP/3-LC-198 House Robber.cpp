class Solution {
public:
    // 1D compressed Linear prefix (choose/skip)	
    // O(n)	O(1)	dp[i]=max(dp[i-1], dp[i-2]+nums[i])	
    // Track two vars (take,skip)
    // Bottom-up; i = 0→n-1 (forward).
    int rob(vector<int>& nums) {
        int prev1=0, prev2=0;
        for(auto &x:nums){
            int curr = max(prev1, prev2+x);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};