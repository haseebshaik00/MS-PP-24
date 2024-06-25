#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s=0, ai=-1, aj=-1 , smax=INT_MIN;
    cin>>n;
    int a[n];
    memset(a, n, 0);
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=i; k<=j; k++)
                s += a[k];
            // smax = max(smax, s);
            if(s>smax){
                ai=i;
                aj=j;
                smax=s;
            }
            s=0;
        }
    }
    cout<<"a["<<ai<<"] + a["<<aj<<"] = "<<smax<<endl;

    return 0;
}
