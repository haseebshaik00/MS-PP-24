#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, x, ans=0;
	cin>>n;
	deque<int> d;
	int a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++){
		cin>>x;
		d.push_back(x);
	}
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++){
		int p = a[i], c=1;
		while(!d.empty() && p != d.front()){
			int x = d.front();
			d.pop_front();
			d.push_back(x);
			c++;
		}
		ans += c;
		d.pop_front();
	}
	cout<<ans;

    return 0;
}
