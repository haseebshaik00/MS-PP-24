#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[100][100];
    int n=3;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0)
                dp[i][j] = a[i][j];
            else if(i == 0)
                dp[i][j] = dp[i][j-1] + a[i][j];
            else if(j==0)
                dp[i][j] = dp[i-1][j] + a[i][j];
            else
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];
        }
    }
    cout<<dp[n-1][n-1]<<endl;

    return 0;
}
