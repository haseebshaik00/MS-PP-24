#include<bits/stdc++.h>
using namespace std;

vector<int> cbPrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

// Check if a number is a CB number
bool isCBNumber(long long num) {
    if (num == 0 || num == 1) return false;
    for (int prime : cbPrimes) {
        if (num == prime) return true;
        if (num % prime == 0) return false;
    }
    return true;
}

// Check if a substring is already visited
bool isValid(int start, int end, vector<bool>& visited) {
    for (int i = start; i < end; i++)
        if (visited[i]) return false;
    return true;
}

int countCBNumbers(string s) {
    int n = s.length();
    vector<bool> visited(n, false);
    int count = 0;

    // Try all substrings of length 1 to n
    for (int len = 1; len <= n; len++) {
        for (int start = 0; start <= n - len; start++) {
            int end = start + len;
            string sub = s.substr(start, len);
            long long num = stoll(sub);

            if (isCBNumber(num) && isValid(start, end, visited)) {
                count++;
                // Mark this range as visited
                for (int i = start; i < end; i++)
                    visited[i] = true;
            }
        }
    }

    return count;
}

int main() {
    string s;
    cin >> s;
    cout << countCBNumbers(s) << endl;
    return 0;
}
