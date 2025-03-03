#include<bits/stdc++.h>
using namespace std;

int mul(int x, int n, int a[]){
	int carr=0, cSum=0;
	for(int i=0; i<n; i++){
		cSum = x * a[i] + carr;
		a[i] = cSum%10;
		carr = cSum/10;
	}
	while(carr){
		a[n] = carr%10;
		n++;
		carr /= 10;
	}
	return n;
}

vector<int> factorial(int n) {
        if(n==0 || n==1) return {1};
        vector<int> v;
        v.push_back(1);
        int c = 0;
        for(int i=2; i<=n; i++){
            c = 0;
            for(int j=0; j<v.size(); j++){
                int x = v[j]*i + c;
                c = x/10;
                v[j] = x%10;
            }
            while(c>0){
                v.push_back(c%10);
                c = c/10;
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, size=1;
	cin>>n;
	int a[1000];
	memset(a, 1000, 0);
	a[0] = 1;
	for(int i=2; i<=n; i++)
		size = mul(i, size, a);
	for(int i=size-1; i>=0; i--)
		cout<<a[i];

	return 0;
}