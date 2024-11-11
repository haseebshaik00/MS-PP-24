// dp[i][j] = 1 if the substring str[0...i-1] matches pattern[0...j-1]

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int isMatch(const string &str, const string &pattern) {
    int m = str.size();
    int n = pattern.size();

    // DP table to store matches for substrings
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;  // Empty pattern matches empty string

    // Fill first row: pattern with * can match empty string
    for (int j = 1; j <= n; ++j) {
        if (pattern[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (pattern[j - 1] == '*') {
                // Match empty sequence or match one or more characters
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else if (pattern[j - 1] == '?' || pattern[j - 1] == str[i - 1]) {
                // Match single character or '?'
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    // Result is whether entire string matches entire pattern
    return dp[m][n] ? 1 : 0;
}

int main() {
    string str, pattern;
    cin >> str >> pattern;
    cout << isMatch(str, pattern) << endl;
    return 0;
}
