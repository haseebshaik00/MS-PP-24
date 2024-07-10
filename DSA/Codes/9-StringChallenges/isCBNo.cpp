#include<bits/stdc++.h>
using namespace std;

bool checkCB(string subStr){
	long long a = stoll(subStr);
	if(a==0 || a==1)
		return false;
	int b[10]= {2,3,5,7,11,13,17,19,23,29};
	int l = sizeof(b)/sizeof(b[0]);
	for(int i=0; i<l; i++){
		if(a == b[i])
			return true;
	}
	for(int i=0; i<l; i++){
		if(a % b[i] == 0)
			return false;
	}
	return true;
}

bool isValid(bool *visited, int i, int j){
	for(int k=i; k<j; k++){
	if(visited[k]) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
    cin>>n;
    string s;
    cin>>s;
    long c = 0;
	bool* visited = new bool[n];
	for(int i=0; i<s.length(); i++)
		visited[i] = false;
	for(int i=1; i<=s.length(); i++){
		for(int j=0; j<=s.length()-i; j++){
			int e = j+i;
			string subStr = s.substr(j, e-j);
			if(checkCB(subStr) && isValid(visited, j, e)){
				c++;
				for(int k=j; k<e; k++)
					visited[k] = true;
			}
		}
	}
	cout<<c<<endl;

	return 0;
}
