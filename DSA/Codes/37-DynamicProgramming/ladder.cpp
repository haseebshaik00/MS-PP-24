#include<bits/stdc++.h>
using namespace std;

int ladder(int n, int k, int dp[]){
    if(n == 0)
        return 1;
    if(dp[n] != 0) return dp[n];
    int ans = 0;
    for(int i=1; i<=k; i++){
        if(n-i >= 0) ans += ladder(n-i, k, dp);
    }
    return dp[n] = ans;
}

// O(N*k)
int ladder2(int n, int k){
    if(n == 0)
        return 1;
    int dp[100];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=k; j++)
            if(i-j >= 0)
                dp[i] += dp[i-j];
    return dp[n];
}

// O(N)
int ladder3(int n, int k){
    if(n == 0)
        return 1;
    int dp[100];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; dp[1] = 1;
    for(int i=2; i<=k; i++)
        dp[i] = 2*dp[i-1];
    for(int i=k+1; i<=n; i++)
        dp[i] = 2*dp[i-1] - dp[i-1-k];
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    int dp[100];
    memset(dp, 0, sizeof(dp));
    cout<<ladder(n, k, dp)<<" "<<ladder2(n, k)<<" "<<ladder3(n, k);

    return 0;
}
