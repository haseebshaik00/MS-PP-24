long long int optGame(int a[], int n, int i, int j, vector<vector<long long int>> &dp){
        if(i>j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        long long int op1 = a[i] + min(optGame(a, n, i+2, j, dp), optGame(a, n, i+1, j-1, dp));
        long long int op2 = a[j] + min(optGame(a, n, i+1, j-1, dp), optGame(a, n, i, j-2, dp));
        return dp[i][j] = max(op1, op2);
    }
    
    long long maximumAmount(int n, int arr[]){
        vector<vector<long long int>> dp(n, vector<long long int>(n, -1));
        return optGame(arr, n, 0, n-1, dp);
    }