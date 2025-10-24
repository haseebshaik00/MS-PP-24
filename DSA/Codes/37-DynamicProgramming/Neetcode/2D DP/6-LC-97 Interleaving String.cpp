class Solution {
public:
    int l=0, m=0;
    vector<vector<int>> dp;

    // Recursion - TOP DOWN | O(2^n) | O(1)
    // bool dfs(const string &s1, const string &s2, const string &s3, int i, int j){
    //     if (i == l && j == m) return true;
    //     bool res = false;
    //     if(i<l && (s3[i+j] == s1[i])) res = dfs(s1, s2, s3, i+1, j);
    //     if(!res && j<m && (s3[i+j] == s2[j])) res = dfs(s1, s2, s3, i, j+1);
    //     return res;
    // }

    // bool isInterleave(string s1, string s2, string s3) {
    //     l=s1.length(), m=s2.length();
    //     if(l+m != s3.length()) return false;
    //     return dfs(s1, s2, s3, 0, 0);
    // }

    // 2D DP - TOP DOWN | O(m*n) | O(m*n)
    // bool dfs(const string &s1, const string &s2, const string &s3, int i, int j){
    //     if (i == l && j == m) return true;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     bool res = false;
    //     if(i<l && (s3[i+j] == s1[i]) && dfs(s1, s2, s3, i+1, j)) res = true;
    //     if(!res && j<m && (s3[i+j] == s2[j]) && dfs(s1, s2, s3, i, j+1)) res = true;
    //     return dp[i][j] = res;
    // }

    // bool isInterleave(string s1, string s2, string s3) {
    //     l=s1.length(), m=s2.length();
    //     dp.assign(l+1, vector<int>(m+1, -1));
    //     if(l+m != s3.length()) return false;
    //     return dfs(s1, s2, s3, 0, 0);
    // }

    // Bottom-up (2D DP) — O(m·n) time, O(m·n) space
    // bool isInterleave(string s1, string s2, string s3) {
    //     l=s1.length(), m=s2.length();
    //     dp.assign(l+1, vector<int>(m+1, 0));
    //     if(l+m != s3.length()) return false;
    //     dp[0][0] = 1;
    //     // dp[i][j] = can s1[0..i-1] and s2[0..j-1] form s3[0..i+j-1]?
    //     for(int i=1; i<=l; ++i) dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
    //     for(int j=1; j<=m; ++j) dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
    //     for(int i=1; i<=l; ++i){
    //         for(int j=1; j<=m; ++j){
    //             char c = s3[i+j-1];
    //             dp[i][j] = (dp[i][j-1] && s2[j-1] == c) || 
    //                         (dp[i-1][j] && s1[i-1] == c);
    //         }
    //     }
    //     return dp[l][m];
    // }

    // Space-optimized DP (1-D) — O(m·n) time, O(n) space
    bool isInterleave(string s1, string s2, string s3) {
        l=s1.length(), m=s2.length();
        if(l+m != s3.length()) return false;
        vector<int> dp(m+1, 0); dp[0] = 1;
        for(int j=1; j<=m; ++j) dp[j] = dp[j-1] && (s3[j-1] == s2[j-1]);
        for(int i=1; i<=l; ++i){
            dp[0] = dp[0] && (s3[i-1] == s1[i-1]);
            for(int j=1; j<=m; ++j){
                char c = s3[i+j-1];
                dp[j] = (dp[j-1] && (c == s2[j-1])) ||
                        (dp[j] && (c == s1[i-1]));
            }
        }
        return dp[m];
    }
};