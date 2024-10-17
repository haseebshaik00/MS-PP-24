#include<bits/stdc++.h>
using namespace std;

int friendsPair(int n){
    if(n<=2)
        return n;
    int dp[n+1] = {0};
    dp[1]=1; dp[2]=2;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + (i-1)*dp[i-2];
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    cout<<friendsPair(n);

    return 0;
}
