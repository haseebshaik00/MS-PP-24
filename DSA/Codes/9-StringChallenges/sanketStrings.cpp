#include<bits/stdc++.h>
using namespace std;

int maxWindow(string a, int k, char ch){
	int i=0, j=0, c=0, ans=0, cMax=0, n=a.length();
	for(; j<n-1; j++){
		if(a[j] != ch) c++;
		if(c==k) break;
	}
	while(i<j){
		while(j<n-1 && a[j+1] == ch) j++;
		cMax = j-i+1;
		ans = max(ans, cMax);
		i++;
		if(j<n-1 && a[i-1] != ch) j++;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin>>k;
	cin.ignore();
	string s;
	getline(cin, s);
	cout<<max(maxWindow(s, k, 'a'), maxWindow(s, k, 'b'));

	return 0;
}