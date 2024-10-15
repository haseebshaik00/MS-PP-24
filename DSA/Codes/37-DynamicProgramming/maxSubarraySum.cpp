#include<bits/stdc++.h>
using namespace std;

int wineProb(int a[], int n, int i, int j, int y, int dp[][100]){
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(a[i]*y + wineProb(a, n, i+1, j, y+1, dp),
                          a[j]*y + wineProb(a, n, i, j-1, y+1, dp));
}

int wineProb2(int a[], int n){
    int dp[n][n], y=n;
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            if(i>j)
                dp[i][j]=0;
            else if (i == j)
                dp[i][j] = a[i]*y;
            else
                dp[i][j] = max(a[i]*y + dp[i+1][j], a[j]*y + dp[i][j-1]);
        }
        y--;
    }
    return dp[0][n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[100][100];
    memset(dp, -1, sizeof(dp));

    int n;
    cin>>n;
    int a[n] = {0};
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<wineProb(a, n, 0, n-1, 1, dp)<<" "<<wineProb2(a, n);

    return 0;
}
