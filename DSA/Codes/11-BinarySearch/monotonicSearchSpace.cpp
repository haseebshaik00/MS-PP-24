#include<bits/stdc++.h>
using namespace std;

float sqrtRoot(int n, int p){
    int i=0, j=n, mid, m;
    float ans;
    while(i<=j){
        mid = (i+j)/2;
        m = mid*mid;
        if(m == n)
            return mid;
        else if(m < n){
            ans = mid;
            i = mid+1;
        }
        else j = mid - 1;
    }
    float inc = 0.1;
    for(int i=1; i<=p; i++){
        while(ans * ans < n)
            ans += inc;
        ans -= inc;
        inc /= 10;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin>>n>>p;
    cout<<sqrtRoot(n, p);

    return 0;
}
