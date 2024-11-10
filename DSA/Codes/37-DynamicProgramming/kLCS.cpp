#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kOrderedLCS(vector<int>& seq1, vector<int>& seq2, int n, int m, int k) {
    // dp[i][j][l]: Maximum LCS length for first i elements of seq1 and first j elements of seq2 with l changes allowed
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int l = 0; l <= k; l++) {
                // Case 1: Elements match
                if (seq1[i - 1] == seq2[j - 1]) {
                    dp[i][j][l] = dp[i - 1][j - 1][l] + 1;
                } else {
                    // Case 2: Do not match, we have two options:
                    // 2a: Don't change seq1[i - 1] and take the maximum LCS without changes
                    dp[i][j][l] = max(dp[i - 1][j][l], dp[i][j - 1][l]);
                    
                    // 2b: If changes are allowed, change seq1[i - 1] to match seq2[j - 1] and take LCS with one less change
                    if (l > 0) {
                        dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][l - 1] + 1);
                    }
                }
            }
        }
    }

    // The answer is the LCS of both sequences with up to k modifications
    return dp[n][m][k];
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> seq1(n), seq2(m);
    
    for (int i = 0; i < n; i++) cin >> seq1[i];
    for (int j = 0; j < m; j++) cin >> seq2[j];
    
    cout << kOrderedLCS(seq1, seq2, n, m, k) << endl;
    
    return 0;
}
