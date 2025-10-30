// 2D (Top Down)	Pattern DP (., *)	O(nm)	O(m)	
// `if p[j-1]!='*': dp[i][j]=match && dp[i-1][j-1]; 
// else dp[i][j]=dp[i][j-2]	match = (s[i-1]==p[j-2] or p[j-2]=='.').	
// Bottom-up; i = 0→n; j = 1→m; init j for '*' cases.	


class Solution {
public:
    int m=0, n=0;
    vector<vector<int>> dp;

    // Idea: dp(i, j) = does s[i:] match p[j:]?
    bool dfs(string s, string p, int i, int j){
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        if(j==n) ans = (i==m);
        else{
            bool first = i<m && (s[i] == p[j] || p[j] == '.');
            if(j+1 < n && p[j+1] == '*') 
                ans = dfs(s, p, i, j+2) || (first && dfs(s, p, i+1, j));
            else ans = first && dfs(s, p, i+1, j+1);
        }
        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        m=s.size(), n=p.size();
        dp.assign(m+1, vector<int>(n+1, -1));
        return dfs(s, p, 0, 0);
    }
};