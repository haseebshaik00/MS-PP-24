#include<bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int m, int mid){
    int s = 1, read = 0;
    for(int i=0; i<n; i++){
        if(read + a[i] > mid){
            read = a[i];
            s++;
            if(s>m) return false;
        }
        else{
            read += a[i];
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i=INT_MIN, j=0, mid, ans, d;
    cin>>n>>m;
    int a[n];
    memset(a, 0, n);
    for(int k=0; k<n; k++){
        cin>>a[k];
        j += a[k];
        i = max(i, a[k]);
    }
    if(m > n){
        cout<<"-1"<<endl;
        return 0;
    }
    while(i<=j){
        mid = (i+j)/2;
        if(isPossible(a, n, m, mid)){
            ans = mid;
            j = mid-1;
        }
        else i = mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
