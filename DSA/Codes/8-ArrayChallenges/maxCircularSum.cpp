#include<bits/stdc++.h>
using namespace std;

int kadaneAlgo(int a[], int n){
	int sMax= INT_MIN, cSum=0;
	for(int i=0; i<n; i++){
		cSum += a[i];
		if(cSum<0) cSum = 0;
		sMax = max(sMax, cSum);
	}
	return sMax;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n, totalSum=0;
		cin>>n;
		int a[n];
		memset(a, n, 0);
		for(int i=0; i<n; i++)
			cin>>a[i];
		int maxA = kadaneAlgo(a, n);
		for(int i=0; i<n; i++){
			totalSum += a[i];
			a[i] = -1 * a[i];
		}
		cout<<max(maxA, totalSum + kadaneAlgo(a, n))<<endl;
	}

	return 0;
}


class Solution {
  public:
    int circularSubarraySum(vector<int> &arr) {
        // code here
        int n = arr.size(), totalSum=0;
        int currSum=0, maxSum = arr[0], currSumMin=0, minSum = arr[0];
        for(auto &x: arr){
            totalSum += x;
            currSum = max(x, x+currSum);
            maxSum = max(currSum, maxSum);
            currSumMin = min(x, x+currSumMin);
            minSum = min(currSumMin, minSum);
        }
        if(maxSum < 0) return maxSum;
        return max(maxSum, totalSum - minSum);
    }
};