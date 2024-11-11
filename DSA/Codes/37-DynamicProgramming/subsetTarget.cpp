#include <iostream>
#include <vector>
using namespace std;

// Helper function to solve the problem recursively with memoization
bool subsetSum(int* arr, int n, int target, vector<vector<int>>& dp) {
    // Base case: sum is 0, so it's always possible
    if (target == 0) return true;
    
    // Base case: no elements left but target > 0, not possible
    if (n == 0) return false;
    
    // Check if the result for this subproblem is already computed
    if (dp[n][target] != -1) return dp[n][target];
    
    // If the current element is greater than the target, exclude it
    if (arr[n-1] > target) {
        dp[n][target] = subsetSum(arr, n-1, target, dp);
    } else {
        // Either exclude the current element or include it
        dp[n][target] = subsetSum(arr, n-1, target, dp) || subsetSum(arr, n-1, target - arr[n-1], dp);
    }
    
    return dp[n][target];
}

int main() {
    int n, target;
    cin >> n >> target;
    int* arr = new int[n];
    
    // Read the input array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Create a memoization table and initialize all values to -1
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    
    // Call the recursive function
    if (subsetSum(arr, n, target, dp)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    delete[] arr; // Clean up dynamically allocated array
    return 0;
}
