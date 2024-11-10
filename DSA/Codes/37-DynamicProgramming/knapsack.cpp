int maxAmt(vector<int> &values, vector<int> &weights, int i, int w, vector<vector<int>> &dp){
	if(i<0)
		return 0;
	if(dp[i][w] != -1)
		return dp[i][w];
	int inc=0, exc=0;
	if(w-weights[i] >= 0){
		inc = values[i] + maxAmt(values, weights, i-1, w-weights[i], dp);
	}
	exc = maxAmt(values, weights, i-1, w, dp);
	return dp[i][w] = max(inc, exc);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int>(w+1, -1));
	return maxAmt(values, weights, n-1, w, dp);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
  vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
  for (int i = 0; i <= n; i++){
	  for(int j=0; j<=w; j++){
		  if(i==0 || j==0)
		  	dp[i][j] = 0;
		  else if(j-weights[i-1] >= 0)
			  dp[i][j] = max(dp[i-1][j], values[i-1]+dp[i-1][j-weights[i-1]]);
		  else
			  dp[i][j] = dp[i-1][j];
	  }
  }
  return dp[n][w];
}