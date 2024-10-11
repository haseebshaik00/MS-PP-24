#include<bits/stdc++.h>
using namespace std;

int knapsack(int w[], int p[], int n, int k){
    if(n==0 || k==0)
        return 0;
    int inc=0, exc=0;
    if(w[n-1]<=k)
        inc = p[n-1] + knapsack(w, p, n-1, k-w[n-1]);
    exc = knapsack(w, p, n-1, k);
    return max(inc, exc);
}

// Soln 2
void knapsack(vector<int> v,vector<int> we,int n,int w, int i, int tp, int tw, int &ans){
	if(i >= n){
		ans = max(ans, tp);
		return;
	}
	if(tw+we[i] <= w)
		knapsack(v, we, n, w, i+1, tp+v[i], tw+we[i], ans);
	knapsack(v, we, n, w, i+1, tp, tw, ans);
	return;
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	int totalProfit = 0, totalWeight=0, ans=0;
	knapsack(values, weights, n, w, 0, totalProfit, totalWeight, ans);
	return ans;
}

// Doesn't work for large n values - use DP in that case
// 0-1 Knapsack can be done using only recursion, DP and not Greedy Algo
// Fractional Knapsack can be done using all 3 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n;
    int w[n], p[n];
    memset(w, 0, n);
    memset(p, 0, n);
    for(int i=0; i<n; i++)
        cin>>w[i];
    for(int i=0; i<n; i++)
        cin>>p[i];
    cin>>k;
    cout<<knapsack(w, p, n, k);

    return 0;
}
