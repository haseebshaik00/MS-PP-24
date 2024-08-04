#include<bits/stdc++.h>
using namespace std;

vector<string> s;

string keypad[] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string searchIn[] = { "kartik", "sneha", "deepak", "arnav", "shikha", "palak","utkarsh", "divyam", "vidhi", "sparsh", "akku"};

void smartKeyboard(char c[], int i){
	if(c[i] == '\0'){
		string s1(c);
		for(int i=0; i<=10; i++){
			if(searchIn[i].find(s1) != string::npos)
				s.push_back(searchIn[i]);
		}
		return;
	}
	int d = (c[i] - '0');
	string s = keypad[d];
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
	for(auto x:s)
		cout<<x<<endl;

	return 0;
}
