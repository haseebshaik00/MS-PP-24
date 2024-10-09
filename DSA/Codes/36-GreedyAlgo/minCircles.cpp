#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans=1;
	cin>>n;
	int c, r;
	vector<pair<int, int>> v;
	for(int i=0; i<n;i++){
		cin>>c>>r;
		v.push_back({c-r, c+r});
	}
	sort(v.begin(), v.end(), comp);
	int prev=v[0].second;
	for(int i=1; i<n; i++){
		if(v[i].first >= prev){
			ans++;
			prev = v[i].second;
		}
	}
	cout<<n-ans<<endl;

	return 0;
}