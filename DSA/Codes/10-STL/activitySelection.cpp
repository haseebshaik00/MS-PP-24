#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n, c=1, currentMax= 0;
		cin>>n;
		pair<int, int> p[n];
		for(int i=0; i<n; i++)
			cin>>p[i].first>>p[i].second;
		sort(p, p+n, comp);
		currentMax = p[0].second;
		for(int i=1; i<n; i++){
			if(p[i].first >= currentMax){
				currentMax = p[i].second;
				c++;
			}
		}
		cout<<c<<endl;
	}

	return 0;
}
