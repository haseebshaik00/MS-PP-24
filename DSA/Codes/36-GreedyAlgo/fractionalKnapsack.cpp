//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
  
    static bool comp(Item a, Item b){
        double aP = a.value/(a.weight * 1.0);
        double bP = b.value/(b.weight * 1.0);
        return aP > bP;
    }
    
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        int m = n;
        sort(arr, arr+m, comp);
        int curr_weight=0, i=0;
        double totalProfit=0;
        while(curr_weight + arr[i].weight <= w && i<n){
            curr_weight += arr[i].weight;
            totalProfit += arr[i].value;
            i++;
        }
        if(curr_weight != w && i < n){
            int remainWeight = (w - curr_weight);
            double f = remainWeight/(1.0 * arr[i].weight);
            totalProfit += (arr[i].value * f);
        }
        return totalProfit;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends