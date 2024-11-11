#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> memo;

long long max_gold(long long n) {
    if (n == 0) return 0;
    if (memo[n]) return memo[n];
    return memo[n] = max(n, max_gold(n / 2) + max_gold(n / 3) + max_gold(n / 4));
}

int main() {
    long long n;
    cin >> n;
    cout << max_gold(n) << endl;
    return 0;
}
