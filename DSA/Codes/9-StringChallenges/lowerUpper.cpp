#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char c;
	cin>>c;
	if(c>='a' && c<='z') cout<<"lowercase";
	else if(c>='A' && c<='Z') cout<<"UPPERCASE";
	else cout<<"Invalid";

	return 0;
}