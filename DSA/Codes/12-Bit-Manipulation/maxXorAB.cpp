#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin>>a>>b;
    int c = a^b, p=0;
	while(c){
		p++;
		c=c>>1;
	}
	cout<<((1<<p)-1);

    return 0;
}
