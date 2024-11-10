#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w;
	cin>>n>>w;
	vector<int> weight(n), val(n), dp(w+1, 0);
	for(int i=0; i<n; i++)
		cin>>weight[i];
	for(int i=0; i<n; i++)
		cin>>val[i];
	for(int i=0; i<=w; i++)
		for(int j=0; j<n; j++)
			if(i-weight[j] >= 0)
				dp[i] = max(dp[i], dp[i-weight[j]] + val[j]);
	cout<<dp[w];

    return 0;
}
