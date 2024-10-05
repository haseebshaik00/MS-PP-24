#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    getline(cin, s);
    getline(cin, t);

    int n1 = s.length(), n2 = t.length();
    
    // If t is longer than s, no solution is possible
    if (n2 > n1) {
        cout << "No String";
        return 0;
    }

    // Arrays to store frequency of characters in s and t
    int FS[256] = {0}, FT[256] = {0};

    // Store frequency of characters in string t
    for (int i = 0; i < n2; i++) {
        FT[t[i]]++;
    }

    int cnt = 0;          // Count of characters matched between s and t
    int minIdx = INT_MAX;  // Store the length of the minimum window
    int start = 0;         // Start index of the current window
    int startIdx = -1;     // Start index of the smallest window

    // Traverse the string s
    for (int i = 0; i < n1; i++) {
        char ch = s[i];
        FS[ch]++;

        // If the current character in s is part of t and hasn't exceeded its required count
        if (FT[ch] != 0 && FS[ch] <= FT[ch])
            cnt++;

        // If all characters of t are matched in the current window
        if (cnt == n2) {
            // Try shrinking the window from the left
            char c = s[start];
            while (FT[c] == 0 || FS[c] > FT[c]) {
                if (FS[c] > FT[c])
                    FS[c]--;
                start++;
                c = s[start];
            }

            // Check if the current window is the smallest so far
            int windowLen = i - start + 1;
            if (windowLen < minIdx) {
                minIdx = windowLen;
                startIdx = start;
            }
        }
    }

    // Output the result
    if (startIdx == -1)
        cout << "No String";
    else
        cout << s.substr(startIdx, minIdx);

    return 0;
}
