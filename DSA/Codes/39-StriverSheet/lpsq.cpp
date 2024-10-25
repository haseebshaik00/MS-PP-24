class Solution {
public:
    // int lcsTopDown(string s, string t, vector<vector<int>> &dp, int i, int j){
    //     if(i==s.length() || j==t.length()) 
    //         return 0;
    //     if(dp[i][j] != 0) return dp[i][j];
    //     if(s[i] == t[j]) return dp[i][j] = 1 + lcs(s, t, dp, i+1, j+1);
    //     int op1 = lcs(s, t, dp, i+1, j);
    //     int op2 = lcs(s, t, dp, i, j+1);
    //     return dp[i][j] = max(op1, op2);
    // }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n=s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=1; i<=n; i++){    
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};