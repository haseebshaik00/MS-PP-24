#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
	cin>>t;
	while(t--){
		cin>>n;
		int p, q;
		vector<pair<int, int>> v;
		for(int i=0; i<n; i++){
			cin>>p>>q;
			v.push_back(make_pair(p, q));
		}
		sort(v.begin(), v.end(), comp);
		int ans = 1, chosen = 0;
        for(int i=1; i<n; i++) {
            if(v[i].first>=v[chosen].second) {
                ans++;
                chosen = i;
            }
        }
		cout<<ans<<endl;
	}

    return 0;
}
