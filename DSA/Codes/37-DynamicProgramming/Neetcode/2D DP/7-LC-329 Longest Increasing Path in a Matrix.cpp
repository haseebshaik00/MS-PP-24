class Solution {
public:
    long long int m=0, n=0, ans=0;
    vector<vector<long long int>> dp;

    long long int dfs(vector<vector<int>>& matrix, int i, int j){
        if(i<0 || j<0 || j>=n || i>=m) return 0;
        long long int &res = dp[i][j];
        if(res) return res; res=1;
        if(i+1 < m && matrix[i+1][j] > matrix[i][j]) res=max(res, 1+dfs(matrix, i+1, j));
        if(j+1 < n && matrix[i][j+1] > matrix[i][j]) res=max(res, 1+dfs(matrix, i, j+1));
        if(i-1 >= 0 && matrix[i-1][j] > matrix[i][j]) res=max(res, 1+dfs(matrix, i-1, j));
        if(j-1 >= 0 && matrix[i][j-1] > matrix[i][j]) res=max(res, 1+dfs(matrix, i, j-1));
        return dp[i][j] = res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size(), n=matrix[0].size();
        dp.assign(m, vector<long long int>(n, 0));
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                ans = max(ans, dfs(matrix, i, j));
        return ans;
    }
};