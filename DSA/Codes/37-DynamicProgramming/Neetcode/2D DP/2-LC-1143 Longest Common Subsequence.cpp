class Solution {
public:
    /* 2D DP O(n^2) | O(n^2)
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length(), n=text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    */

    // 2D (row-compressible)	Two-sequence DP	O(nm)	O(min(n,m))	
    // dp[i][j]= a[i-1]==b[j-1]? prev[j-1]+1 : max(prev[j],cur[j-1])	
    // Usually keep two rows.	Bottom-up; i = 1→n, j = 1→m (forward).
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length(), n=text2.length();
        vector<int> dp(n+1, 0);
        for(int i=1; i<=m; ++i){
            int prevDiag = 0; // holds dp[j-1] from previous row (the diagonal)
            for(int j=1; j<=n; ++j){
                int temp = dp[j]; // save old dp[j] (previous row)
                if(text1[i-1] == text2[j-1]) dp[j] = 1 + prevDiag;
                else dp[j] = max(dp[j-1], dp[j]);
                prevDiag = temp; // advance diagonal
            }
        }
        return dp[n];
    }
};