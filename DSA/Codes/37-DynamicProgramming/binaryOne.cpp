ll countStrings(int n) {
	    vector<pair<ll, ll>> dp(n+1, {0, 0});
	    dp[1].first=1; dp[1].second=1;
	    for(int i=2; i<=n; i++){
	        dp[i].first = (dp[i-1].first + dp[i-1].second)%1000000007;
	        dp[i].second = dp[i-1].first;
	    }
	    return (dp[n].second+dp[n].first)%1000000007;
	}