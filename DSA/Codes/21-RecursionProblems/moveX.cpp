#include<bits/stdc++.h>
using namespace std;

void moveX(char c[], int i, int j){
	if(i >= j){
		cout<<c;
		return;
	}
	if(c[i] == 'x'){
		int j = i;
		while(c[j] != '\0' && c[j+1] != '\0')
		{
			swap(c[j], c[j+1]);
			j++;
		}
	}
	moveX(c, i+1, j);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char c[1004];
	cin>>c;
	int j = strlen(c);
	moveX(c, 0, j-1);

	return 0;
}
