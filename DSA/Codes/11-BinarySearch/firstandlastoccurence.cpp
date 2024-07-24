#include<bits/stdc++.h>
using namespace std;

int firstOccurence(int a[], int n, int k){
    int i=0, j=n-1 ,mid, ans=-1;
    while(i<=j){
        mid = (i+j)/2;
        if(a[mid] == k){
            ans = mid;
            j = mid-1;
        }
        else if(a[mid] > k) j=mid-1;
        else i=mid+1;
    }
    return ans;
}

int lastOccurence(int a[], int n, int k){
    int i=0, j=n-1 ,mid, ans=-1;
    while(i<=j){
        mid = (i+j)/2;
        if(a[mid] == k){
            ans = mid;
            i = mid+1;
        }
        else if(a[mid] > k) j=mid-1;
        else i=mid+1;
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
    cout<<firstOccurence(a, n, k)<<endl;
    cout<<lastOccurence(a, n, k)<<endl;

    cout<<lower_bound(a, a+n, 8)-a<<" "<<upper_bound(a, a+n, 8)-a-1<<endl;

    return 0;
}
