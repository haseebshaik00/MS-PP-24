class Solution {
public:
    // 2D (Top Down)	Interval DP	O(n³)	O(n²)	
    // Pad with 1s: dp[l][r]=max_{k∈(l,r)} dp[l][k]+dp[k][r]+val[l]*val[k]*val[r]	
    // Work by interval length. | Pad nums with 1s; iterate by interval length.	
    // If Bottom-up; len = 2→n+1; l = 0→n-len (forward).
    vector<int> v;
    int dfs(vector<vector<int>> &dp, int l, int r){
        if(r-l <= 1) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = -1;
        for(int i=l+1; i<r; ++i)
            ans = max(ans, dfs(dp, l, i) + v[l]*v[i]*v[r]+ dfs(dp, i, r));
        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        v.reserve(n+2);
        v.push_back(1);
        for(auto &x: nums) if(x>0) v.push_back(x);
        v.push_back(1);
        n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(dp, 0, n-1);
    }
};