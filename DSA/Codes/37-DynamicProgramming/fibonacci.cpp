#include<bits/stdc++.h>
using namespace std;

int fibTD(int n, int dp[]){
    if(n==0 || n==1){
        dp[n] = n;
        return n;
    }
    if(dp[n]!=0) return dp[n]; //lookup -- overlapping subproblems
    return dp[n] = fibTD(n-1, dp) +  fibTD(n-2, dp); // optimal substructure
}

int fibBU(int n){
    int dp2[n+1] = {0};
    dp2[1]=1;
    for(int i=2; i<=n; i++)
        dp2[i] = dp2[i-1] + dp2[i-2];
    return dp2[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int dp[n+1]={0};
    cout<<fibTD(n, dp)<<" "<<fibBU(n);

    return 0;
}
