#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n;
    int a[n];
    memset(a, n, 0);
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>k;
    int i=0, j=n-1, s=0;
    while(i<j){
        s = a[i] + a[j];
        if(s>k) j--;
        else if(s<k) i++;
        else{
                cout<<a[i]<<" + "<<a[j]<<" = "<<k<<endl;
                i++;j--;
        }
    }

    return 0;
}
