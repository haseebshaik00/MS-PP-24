#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findNthUglyNumber(int n) {
    vector<int> uglyNumbers(n);
    uglyNumbers[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0; // Pointers for multiples of 2, 3, and 5
    int nextMultipleOf2 = 2;
    int nextMultipleOf3 = 3;
    int nextMultipleOf5 = 5;

    for (int i = 1; i < n; ++i) {
        // Choose the smallest next multiple
        int nextUgly = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
        uglyNumbers[i] = nextUgly;

        // Update pointers for the chosen factor(s)
        if (nextUgly == nextMultipleOf2) {
            i2++;
            nextMultipleOf2 = uglyNumbers[i2] * 2;
        }
        if (nextUgly == nextMultipleOf3) {
            i3++;
            nextMultipleOf3 = uglyNumbers[i3] * 3;
        }
        if (nextUgly == nextMultipleOf5) {
            i5++;
            nextMultipleOf5 = uglyNumbers[i5] * 5;
        }
    }

    return uglyNumbers[n - 1];
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n;
        cout << findNthUglyNumber(n) << endl;
    }
    return 0;
}
