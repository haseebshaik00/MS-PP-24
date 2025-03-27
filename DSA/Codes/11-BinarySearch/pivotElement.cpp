#include<bits/stdc++.h>
using namespace std;

int findElement(int a[], int n, int k){
    int i=0, j=n-1, mid;
    while(i<=j){
        mid = (i+j)/2;
        if(a[mid] == k)
            return mid;
        else if(a[i] <= a[mid]){
            if(a[i] <= k & k <= a[mid]) j=mid-1;
            else i=mid+1;
        }
        else{
            if(a[j] >= k & k >= a[mid]) i=mid+1;
            else j=mid-1;
        }
    }
    return -1;
}

int findMin(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=n-1, ans=INT_MAX;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[i]<=nums[mid]){
                ans = min(nums[i], ans);
                i=mid+1;
            }
            else{
                ans = min(nums[mid], ans);
                j=mid-1;
            }
        }
        return ans;
    }
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n;
    int a[n];
    memset(a, 0, n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>k;
    cout<<findElement(a, n, k);

    return 0;
}
