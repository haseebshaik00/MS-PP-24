#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, n;
    cin>>a>>b>>n;
    vector<int> x, y;
    for(int i=0; i<n; i++){
        int p, q;
        cin>>p>>q;
        x.push_back(p);
        y.push_back(q);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int dx=x[0]-1, dy=y[0]-1;
    for(int i=1; i<n; i++){
        dx = max(dx, x[i] - x[i-1]-1);
        dy = max(dy, y[i] - y[i-1]-1);
    }
    // corner case
    dx = max(dx, a-x[n-1]);
    dy = max(dy, b-y[n-1]);
    cout<<(dx*dy)<<endl;

    return 0;
}
