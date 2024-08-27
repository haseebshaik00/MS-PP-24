#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	stack<int> s; // for storing index
	vector<int> v; // for storing span
	s.push(0);
	v.push_back(1);
	for(int i=1; i<n; i++){
		int cPrice = a[i];
		while(!s.empty() && cPrice >= a[s.top()])
			s.pop();
		if(!s.empty()){
			int prev_high = s.top();
            v.push_back(i-prev_high);
		}
		else{
			v.push_back(i+1);
		}
		s.push(i);
	}
	for(auto x:v)
		cout<<x<<" ";
	cout<<"END";

	return 0;
}
