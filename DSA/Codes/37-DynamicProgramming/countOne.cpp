#include<bits/stdc++.h>
using namespace std;

int countOne(vector<int> &v, int n, int k){
	int bestLeft=0, left=0, maxLen=0, zeroCount=0;
	for(int right=0; right<n; right++){
		if(v[right] == 0)
			zeroCount++;
		while(zeroCount > k){
			if(v[left] == 0)
				zeroCount--;
			left++;
		}
		if(right-left+1 > maxLen){
			maxLen = right-left+1;
			bestLeft=left;
		}
	}
	for(int i=bestLeft; i<bestLeft+maxLen; i++){
		if(v[i] == 0 && k>0){
			v[i] = 1;
			k--;
		}
	}
	return maxLen;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin>>v[i];
	cout<<countOne(v, n, k)<<endl;
	for(auto x:v)
		cout<<x<<" ";
	cout<<endl;

    return 0;
}
