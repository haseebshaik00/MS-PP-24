#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, c;
	getline(cin, a);
	getline(cin, b);
	getline(cin, c);
	int n1=a.length(), n2=b.length(), n3=c.length();
	int dp[n1+1][n2+1][n3+1];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n1; i++){
		for(int j=1; j<=n2; j++){
			for(int k=1; k<=n3; k++){
				if(a[i-1]==b[j-1] && b[j-1]==c[k-1])
					dp[i][j][k] = 1+dp[i-1][j-1][k-1];
				else
					dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
			}
		}
	}
	cout<<dp[n1][n2][n3];

    return 0;
}
