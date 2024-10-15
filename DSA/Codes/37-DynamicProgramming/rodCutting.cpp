#include<bits/stdc++.h>
using namespace std;

int rodCutting(int price[], int n, int dp[]){
    if(n <= 0)
        return 0;
    if(dp[n] != 0) return dp[n];
    int ans = INT_MIN, currMax=0;
    for(int i=0; i<n; i++){
        currMax = price[i] + rodCutting(price, n-i-1, dp);
        ans = max(ans, currMax);
    }
    return dp[n] = ans;
}

int rodCutting2(int price[], int n){
    if(n <= 0)
        return 0;
    int dp[100];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++){
        int ans = INT_MIN, currMax;
        for(int j=0; j<i; j++){
            currMax = price[j] + dp[i-j-1];
            ans = max(ans, currMax);
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int dp[100];
    memset(dp, 0, sizeof(dp));
    cout<<rodCutting(a, n, dp)<<" "<<rodCutting2(a, n);

    return 0;
}
