#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	getline(cin, s);
	sort(s.begin(), s.end());
	char cMax = s[0];
	int frq = 1, maxFrq = 0;
	for(int i=1; i<s.length(); i++){
		if(s[i] == s[i-1]){
			frq++;
			if(frq >= maxFrq){
				maxFrq = frq;
				cMax = s[i];		
			}
		}
		else frq = 0;
	}
	cout<<cMax;

	return 0;
}