#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
	cin>>s;
	for(auto &x: s)
		if(x>'4') x = '9'-x+'0';
	if(s.front() == '0') s.front() = '9';
	cout<<s;

    return 0;
}
