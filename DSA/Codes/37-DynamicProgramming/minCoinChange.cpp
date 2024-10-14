#include<bits/stdc++.h>
using namespace std;

int minCoin(int a[], int n, int k, int dp[]){
    if(k == 0)
        return 0;
    if(dp[k]!=0)
        return dp[k];
    int ans = INT_MAX;
    for(int i=0; i<n; i++)
        if(k-a[i] >= 0)
            ans = min(ans, minCoin(a, n, k-a[i], dp)+1);
    return dp[k] = ans;
}

int minCoin1(int a[], int n, int k){
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin>>k;
    int a[] = {1, 7, 10};
    int dp[k+1]={0};
    cout<<minCoin(a, 3, k, dp)<<" "<<minCoin1(a, 3, k);

    return 0;
}
