#include<bits/stdc++.h>
using namespace std;

int cSumMix(int s, int e, int a[]){
    int ans=0;
    for(int i=s; i<=e; i++){
        ans += a[i];
        ans %= 100;
    }
    return ans;
}

int mixtures(int a[], int n, int i, int j, int dp[100][100]){
    if(i>=j)
        return 0;
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j] = INT_MAX;
    for(int k=i; k<=j; k++){
        dp[i][j] = min(dp[i][j], mixtures(a, n, i, k, dp) + mixtures(a, n, k+1, j, dp) + cSumMix(i, k, a) * cSumMix(k+1, j, a));
    }
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    memset(a, 0, sizeof(a));
    for(int i=0; i<n; i++)
        cin>>a[i];
    int dp[100][100];
    memset(dp, -1, sizeof(dp));
    cout<<mixtures(a, n, 0, n-1, dp);

    return 0;
}
