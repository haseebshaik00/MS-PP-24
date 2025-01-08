#include<bits/stdc++.h>
using namespace std;

// handles negative nos too
int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0], cSum=0;
        for(int num: nums){
            cSum = max(num, num+cSum); // Respects the logic of Kadane's algorithm by allowing the subarray to restart with the current number.
            maxSum = max(cSum, maxSum);
        }
        return maxSum;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    memset(a, n, 0);
    for(int i=0; i<n; i++)
        cin>>a[i];
    int csum=0, sumMax=INT_MIN;
    for(int i=0; i<n; i++){
        csum += a[i];
        sumMax = max(csum, sumMax);
        csum = csum<0 ? 0 : csum;
    }
    cout<<sumMax<<endl;

    return 0;
}
