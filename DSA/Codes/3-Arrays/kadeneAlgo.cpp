#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0], cSum=0;
        for(int num: nums){
            cSum = max(num, num+cSum);
            maxSum = max(cSum, maxSum);
        }
        return maxSum;
    }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,cSum=0, maxSum=INT_MIN;
	cin>>n;
	int a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++)
		cin>>a[i];
    for(int i=0; i<n; i++){
        cSum = max(cSum+a[i], a[i]);
        maxSum = max(cSum, maxSum);
    }
    cout<<maxSum<<endl;

	return 0;
}