#include<bits/stdc++.h>
using namespace std;

void pfOpt(vector<pair<int, int>> &factor, int n){
    int c;
    for(int i=2; i*i<=n; i++){
        c=0;
        while(n%i == 0){
            c++;
            n /= i;
        }
        if(c) factor.push_back(make_pair(i, c));
    }
    if(n!=1) factor.push_back(make_pair(n, 1));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int, int>> factor;
    pfOpt(factor, n);
    for(auto x:factor)
        cout<<x.first<<" "<<x.second<<endl;

    return 0;
}
