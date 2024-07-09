#include<bits/stdc++.h>
using namespace std;

string isPal(char c[], int i, int j){
	if(i >= j) return "true";
	if(c[i] != c[j]) return "false";
	return isPal(c, ++i, --j);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	char c[n];
	cin.get();
	for(int i=0; i<n; i++)
		cin>>c[i];
	if(n==0 || n==1){
		cout<<"true";
		return 0;
	}
	cout<<isPal(c, 0, n-1);

	return 0;
}