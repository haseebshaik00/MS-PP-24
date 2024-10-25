#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    int m, n, p;
    cin >> m >> n >> p;
    
    // Initialize the grid
    vector<vector<int>> a(m, vector<int>(n, 0));
    
    // Mark the obstacles
    while (p--) {
        int c, d;
        cin >> c >> d;
        a[c - 1][d - 1] = -1; // Mark obstacle positions with -1
    }

    // Set the starting point
    if (a[0][0] != -1) {
        a[0][0] = 1;  // If there's no obstacle at the start, set it as 1
    }

    // Fill the DP table
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == -1) {
                continue;  // Skip obstacle cells
            }
            if (i > 0 && a[i - 1][j] != -1) {
                a[i][j] = (a[i][j] + a[i - 1][j]) % MOD;  // Add value from the top cell
            }
            if (j > 0 && a[i][j - 1] != -1) {
                a[i][j] = (a[i][j] + a[i][j - 1]) % MOD;  // Add value from the left cell
            }
        }
    }

    // Output the result at the bottom-right corner
    if (a[m - 1][n - 1] == -1) {
        cout << 0 << endl;  // If the destination is blocked
    } else {
        cout << a[m - 1][n - 1] % MOD << endl;  // Otherwise, print the result
    }

    return 0;
}
