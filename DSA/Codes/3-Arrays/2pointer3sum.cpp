#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, x, y, s=0;
    cin>>n;
    int a[n];
    memset(a, n, 0);
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n);
    cin>>k;
    for(int i=0; i<n-2; i++){
        x = i+1; y=n-1;
        while(x<y){
            s = a[i]+a[x]+a[y];
            if(s == k){
                cout<<a[i]<<" + "<<a[x]<<" + "<<a[y]<<" = "<<k<<endl;
                x++; y--;
            }
            else if(s<k) x++;
            else y--;
        }
    }

    return 0;
}
