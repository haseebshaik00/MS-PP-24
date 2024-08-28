#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, k, i=0;
	cin>>n;
	int a[n];
	memset(a, 0, n);
	for(int i=0; i<n; i++)
		cin>>a[i];
    cin>>k;
    deque<int> q;
    for(; i<k; i++){
        while(!q.empty() && a[i] >= a[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for(; i<n; i++){
        cout<<a[q.front()]<<" ";
        while(!q.empty() && q.front() <= i-k)
            q.pop_front();
        while(!q.empty() && a[i] >= a[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    cout<<a[q.front()]<<" ";

    return 0;
}
