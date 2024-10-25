#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin>>m>>n;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[i][j] = sumK(0,i-1) for dp[k][j] + sumK(0,j-1) dp[i][k];

    return 0;
}
