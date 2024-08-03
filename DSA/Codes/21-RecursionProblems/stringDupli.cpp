#include<bits/stdc++.h>
using namespace std;

void dupli(char c[], int i){
	if(c[i] == '\0')
		return;
	if(c[i] == c[i+1]){
		int j=i, k=i+1;
		while(c[j] == c[i]) j++;
		while(c[j] != '\0')
			swap(c[k++], c[j++]);
		c[k] = '\0';
	}
	dupli(c, i+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char c[1004];
	cin.get(c, 1004);
	dupli(c, 0);
	cout<<c;

	return 0;
}