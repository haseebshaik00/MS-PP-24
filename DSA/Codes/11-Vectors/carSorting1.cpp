#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    int x = pow(a.first, 2) + pow(a.second, 2);
    int y = pow(b.first, 2) + pow(b.second, 2);
    if(x==y){
        return a.first<b.first;
    }
    return x<y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin>>n;
    vector<pair<int, int>> p;
    p.reserve(100);
    for(int i=0; i<n; i++){
        cin>>a>>b;
        p[i].first = a;
        p[i].second = b;
        p.push_back(make_pair(a,b));
    }
    sort(p.begin(), p.end(), comp);
    for(int i=0; i<n; i++){
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }

    return 0;
}
