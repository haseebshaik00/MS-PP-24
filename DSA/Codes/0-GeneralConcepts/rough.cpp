#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int func(string s, int n, int k, char c){
	int i=0, j=0, ans=0, cnt=0;
	for(; i<n; i++){
		if(s[i] != c) cnt++;
		while(cnt > k){
			if(s[j] != c) cnt--;
			j++;
		}
		ans = max(ans, i-j+1);
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; int k;
	cin>>s>>k;
	int n = s.length();
	cout<<max(func(s, n, k, 'a'), func(s, n, k, 'b'));

    return 0;
}
