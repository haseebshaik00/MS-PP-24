class Solution {
public:
    // int row=0, col=0;
    // int dfs(vector<vector<int>> &dp, int i, int j){
    //     if(i>=row || j>=col) return 0;
    //     if(i==row-1 && j==col-1) {return 1;}
    //     if(dp[i][j]) return dp[i][j];
    //     return dp[i][j] = dfs(dp, i, j+1) + dfs(dp, i+1, j);
    // }

    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, 0));
    //     row=m; col=n;
    //     return dfs(dp, 0, 0);
    // }

    // 1D compressed	Grid paths	O(mn)	O(n)	
    // dp[j]+=dp[j-1]	One row; left + up.	
    // Bottom-up; row-wise, j = 1→n-1 (forward)
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int i=m-2; i>=0; --i)   
            for(int j=n-2; j>=0; --j)
                dp[j] += dp[j+1];
        return dp[0];
    }
};