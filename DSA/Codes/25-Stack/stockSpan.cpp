#include<bits/stdc++.h>
using namespace std;

void stockSpan(int a[], int n){
    stack<int> s; // for storing index
	vector<int> v; // for storing span
    v.push_back(1);
    s.push(0);
    for(int i=1; i<n; i++){
        while(!s.empty() && a[s.top()] < a[i])
            s.pop();
        v.push_back(s.empty() ? (i+1) : (i-s.top()));
        s.push(i);
    }
    for(auto x:v)
		cout<<x<<" ";
	cout<<"END";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;
	int a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	stockSpan(a, n);

    return 0;
}
