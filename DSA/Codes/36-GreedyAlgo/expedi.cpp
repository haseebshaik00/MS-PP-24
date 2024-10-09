#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, d, p, ans=0;
        cin>>n;
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            int a, b;
            cin>>a>>b;
            v.push_back({a, b});
        }
        cin>>d>>p;
        sort(v.begin(), v.end(), comp);
        for(int i=0; i<n; i++)
            v[i].first = d - v[i].first;
        int x=0, prev=0;
        priority_queue<int> pq;
        while(x < n){
            if(p >= (v[x].first - prev)){
                p -= (v[x].first - prev);
                pq.push(v[x].second);
                prev = v[x].first;
            }
            else{
                if(pq.empty()){
                    cout<<"-1";
                    return 0;
                }
                p += pq.top();
                pq.pop();
                ans++;
                continue;
            }
            x++;
        }
        d = d - v[x-1].first;
        if(p >= d){
            cout<<ans<<endl;
            return 0;
        }
        while(p < d){
            if(pq.empty()){
                cout<<"-1";
                return 0;
            }
            p += pq.top();
            pq.pop();
            ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}
