#include<bits/stdc++.h>
using namespace std;

char* myStrtok(char *c){
	static char* input = NULL;
	if(c != NULL)
		input = c;
	if(input == NULL)
		return NULL;
	char* output = new char[strlen(input)+1];
	output[0] = input[0];
	int i=1;
	for(; input[i] != '\0'; i++){
		if(!isupper(input[i]))
			output[i] = input[i];
		else{
			output[i] = '\0';
			input += i;
			return output;
		}
	}
	output[i] = '\0';
	input = NULL;
	return output;
}

void extractWords(char c[], int n){
	char* ptr = myStrtok(c);
	while(ptr != NULL){
		cout<<ptr<<endl;
		ptr = myStrtok(NULL);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	getline(cin, s);
	int n = s.length();
	char c[n+1];
	strcpy(c, s.c_str());
	extractWords(c, n);

	return 0;
}