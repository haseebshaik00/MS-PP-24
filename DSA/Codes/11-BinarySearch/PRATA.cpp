#include<bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int p, int mid){
    int totalParatha = 0, currentTime, c;
    for(int i=0; i<n; i++){
        c=1;
        currentTime = a[i];
        while(currentTime <= mid){
            c++;
            totalParatha++;
            currentTime += a[i] * c;
        }
    }
    if(totalParatha >= p) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p, n, k=INT_MIN, mid, ans;
    cin>>p>>n;
    int a[n];
    memset(a, 0, n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        k = max(k, a[i]);
    }

    int i=0, j=(p*(p+1)*k)/2;
    while(i<=j){
        mid = (i+j)/2;
        if(isPossible(a, n, p, mid)){
            ans = mid;
            j = mid-1;
        }
        else i=mid+1;
    }
    cout<<ans;

    return 0;
}
