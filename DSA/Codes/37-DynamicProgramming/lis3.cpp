#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans=INT_MIN;
    cin>>n;
    int a[n], dp[n+1];
    for(int i=1; i<=n; i++)
        dp[i] = INT_MAX;
    dp[0] = INT_MIN;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++){
        int j = upper_bound(dp, dp+n+1, a[i]) - dp;
        if(dp[j-1] < a[i] && a[i]<dp[j])
            dp[j] = a[i];
    }
    for(int i=0; i<=n; i++){
        if(dp[i]!=INT_MAX) ans = i;
        else break;
    }
    cout<<ans<<endl;

    return 0;
}
