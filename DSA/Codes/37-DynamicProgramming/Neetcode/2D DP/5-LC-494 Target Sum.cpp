class Solution {
public:
    /*
        int offset=0, n=0, T=0;
        vector<vector<int>> dp;

        int dfs(vector<int> &nums, int i, int sum){
            if(i == n) return sum == T;
            int key = sum + offset;
            if(key < 0 || key > 2*offset) return 0;
            if(dp[i][key] != -1) return dp[i][key];
            return dp[i][key] = dfs(nums, i+1, sum + nums[i]) +
                                dfs(nums, i+1, sum - nums[i]);
        }

        int findTargetSumWays(vector<int>& nums, int target) {
            offset = accumulate(nums.begin(), nums.end(), 0);
            n=nums.size(); T=target;
            dp.assign(n, vector<int>(2*offset + 1, -1));
            return dfs(nums, 0, 0);
        }
    */

    // We keep counts of ways to reach each “shifted” sum after processing i numbers
    // Time: O(n*S), Space: O(S).
    int findTargetSumWays(vector<int>& nums, int target) {
        int S = accumulate(nums.begin(), nums.end(), 0), n=nums.size();
        int offset = S, W=2*S+1;
        vector<int> dp(W, 0); dp[offset] = 1;
        for(auto &x: nums){
            vector<int> next(W, 0);
            for(int i=0; i<W; ++i) if (dp[i]) {
                int left = i-x, right=i+x;
                if(left>=0 && left<W) next[left] += dp[i];
                if(right>=0 && right<W) next[right] += dp[i];
            }
            dp.swap(next);
        }
        int ansIdx = target + offset;
        return (ansIdx<0 || ansIdx>=W) ? 0 : dp[ansIdx];
    }
};