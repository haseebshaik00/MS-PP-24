#include<bits/stdc++.h>
using namespace std;

set<vector<int>> setV;
vector<int> v;

void sumIt(int a[], int n, int i, int k){
	if(i==n){
		int s=0;
		for(auto x:v)
			s+=x;
		if(s==k)
			setV.insert(v);
		return;
	}
	v.push_back(a[i]);
	sumIt(a, n, i+1, k);
	v.pop_back();
	sumIt(a, n, i+1, k);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin>>n;
	int a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	sort(a, a+n);
	sumIt(a, n, 0, k);
	for(auto x:setV){
		for(auto y:x)
			cout<<y<<" ";
		cout<<endl;
	}

	return 0;
}
