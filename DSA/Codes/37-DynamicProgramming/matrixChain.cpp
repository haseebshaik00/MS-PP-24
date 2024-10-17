int matrixMultiplication(int n, int arr[])
    {
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int len=2; len<n; len++){
            for(int row=0; row<n-len; row++){
                int col = row+len;
                dp[row][col] = INT_MAX;
                for(int k=row+1; k<col; k++){
                    int cost = (dp[row][k] + dp[k][col] + arr[row]*arr[k]*arr[col]);
                    dp[row][col] = min(dp[row][col], cost);
                }
            }
        }
        return dp[0][n-1];
    }