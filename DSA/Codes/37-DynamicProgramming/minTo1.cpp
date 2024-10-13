#include<bits/stdc++.h>
using namespace std;

int minToOne(int n, int dp[]){
    if(n==1) return 0;
    if(dp[n]!=0) return dp[n];
    int op1, op2, op3;
    op1=op2=op3=INT_MAX;
    if(n%3==0) op3 = minToOne(n/3, dp);
    if(n%2==0) op2 = minToOne(n/2, dp);
    op1 = minToOne(n-1, dp);
    return dp[n] = min(op1, min(op2, op3)) + 1;
}

int minToOne2(int n){
    int dp[n+1] = {0};
    dp[1]=0; dp[2]=dp[3]=1;
    for(int i=4; i<=n; i++){
        int x=INT_MAX;
        if(i%3 == 0) x = dp[i/3] + 1;
        if(i%2 == 0) x = min(x, dp[i/2] + 1);
        x = min(x, dp[i-1]+1);
        dp[i] = x;
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int dp[100] = {0};
    cout<<minToOne(n, dp)<<" "<<minToOne2(n);

    return 0;
}
