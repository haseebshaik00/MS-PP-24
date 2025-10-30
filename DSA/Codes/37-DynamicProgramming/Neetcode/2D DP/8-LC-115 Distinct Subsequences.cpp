class Solution {
public:

    // 1D j-backward	Two-sequence counting	O(nm)	O(m)	
    // dp[i][j]=dp[i-1][j]+(s[i-1]==t[j-1]?dp[i-1][j-1]:0)	
    // 1D trick: iterate j downward.	
    // Bottom-up; i = 1→n; j = m→1 (backward on j).
    int numDistinct(string s, string t) {
        int m=s.length(), n=t.length();
        if(n > m) return 0;
        vector<long long int> dp(n+1, 0); dp[0]=1;
        for(int i=1; i<=m; ++i)
            for (int j = min(i, n); j >= 1; --j)
                if(s[i-1] == t[j-1]) dp[j] += dp[j - 1] % INT_MAX;
        return dp[n];
    }
};