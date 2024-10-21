#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y, z;
    cin>>n>>x>>y>>z;

    int dp[n+1] = {-1};

    for(int i=2; i<=n; i++){
        if(i%2 == 0)
            dp[i] = min(dp[i/2]+x, dp[i-1]+y);
        else
            dp[i] = min(dp[i-1]+y, dp[(i+1)/2]+x+z);
    }
    cout<<dp[n];

    return 0;
}
