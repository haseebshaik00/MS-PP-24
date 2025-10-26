class Solution {
public:
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