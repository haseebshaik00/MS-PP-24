#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n]={0}, totalLoad=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        totalLoad += a[i];
    }
    if(totalLoad % n != 0){
        cout<<"-1";
        return 0;
    }
    totalLoad /= n;
    int load =0, maxLoad=INT_MIN, diff=0;
    for(int i=0; i<n; i++){
        diff += (a[i] - totalLoad);
        load = max(-diff, diff);
        maxLoad = max(maxLoad, load);
    }
    cout<<maxLoad<<endl;

    return 0;
}
