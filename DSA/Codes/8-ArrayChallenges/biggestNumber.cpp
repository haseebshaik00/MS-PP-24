#include<bits/stdc++.h>
using namespace std;

bool comp( string a, string b){
	return ( a+b > b+a ) ? true : false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string str[n];
		for(int i=0; i<n; i++)
			cin>>str[i];
		sort(str, str+n, comp);
		for(int i=0; i<n; i++)
			cout<<str[i];
		cout<<endl;
	}

	return 0;
}
