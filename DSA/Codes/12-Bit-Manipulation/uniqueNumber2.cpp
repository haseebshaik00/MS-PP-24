#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, bitXor=0, pos=-1, subAns=0, bitXorCopy=0, subAns1=0;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		bitXor ^= a[i];
	bitXorCopy = bitXor;
	while(pos==-1){
		if(bitXorCopy & 1)
			pos++;
		bitXorCopy>>1;
	}
	for(int i=0; i<n; i++){
		if(a[i] & (1<<pos))
			subAns ^= a[i];
	}
	subAns1 = subAns ^ bitXor;
	cout<<min(subAns, subAns1)<<" "<<max(subAns, subAns1);
    return 0;
}
