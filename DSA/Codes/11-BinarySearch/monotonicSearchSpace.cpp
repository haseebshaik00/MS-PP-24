#include<bits/stdc++.h>
using namespace std;

double sqroot(int n, int p){
    double i=0, j=n, inc=0.1, ans=0.0;
    while(i<=j){
        int mid = (i+j)/2;
        if(mid*mid <= n){
            ans = mid;
            i=mid+1;
        }
        else j=mid-1;
    }
    if(ans*ans == n) return ans;
    for(int i=0; i<p; i++){
        while(ans*ans <= n){
            ans += inc;
        }
        ans -= inc;
        inc= inc/10;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin>>n>>p;
    if(n==0 || n==1) cout<<n<<endl;
    else{
        stringstream ss;
        ss << fixed << setprecision(p) << sqroot(n, p);;
        string formattedResult = ss.str();
        cout<<formattedResult<<endl;
    }

    return 0;
}