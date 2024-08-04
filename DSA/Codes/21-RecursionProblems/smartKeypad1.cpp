#include<bits/stdc++.h>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void smartKeyboard(char c[], int i){
	if(c[i] == '\0'){
		cout<<c<<endl;
		return;
	}
	int d = (c[i] - '0');
	string s = table[d];
	int n = s.length();
	for(int k=0; k<n; k++){
		c[i] = s[k];
		smartKeyboard(c, i+1);
		c[i] = d+'0';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char c[11];
	cin>>c;
	smartKeyboard(c, 0);

	return 0;
}
