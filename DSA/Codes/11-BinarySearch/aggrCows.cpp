#include<bits/stdc++.h>
using namespace std;

bool canKeepCow(int a[], int n, int mid, int c){
    int cnt=1;
    int lastPlace = a[0];
    for(int i=1; i<n; i++){
        if(a[i]-lastPlace >= mid){
            cnt++;
            lastPlace = a[i];
        }
        if(cnt == c) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c, mid, canKeepCows, ans=-1;
    cin>>n>>c;
    int a[n];
    memset(a, 0, n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n);
    int i=0, j=n-1;
    while(i<=j){
        mid = (i+j)/2;
        canKeepCows = canKeepCow(a, n, mid, c);
        if(canKeepCows){
            ans = mid;
            i=mid+1;
        }
        else j=mid-1;
    }
    cout<<ans<<endl;

    return 0;
}
