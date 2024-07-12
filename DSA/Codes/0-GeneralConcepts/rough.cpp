#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s ="haseeb";
	int a[]= {1,2,3};
	for(char it: s)
        cout<<it<<" ";
    cout<<endl;
    int *it = find(a, a+3, 2);
    auto it1 = find(a, a+3, 2);
    cout<<*it<<endl;
    cout<<it1<<" : "<<endl;
    for(auto it=s.begin(); it!=s.end(); it++)
        cout<<*it<<" - ";
	return 0;
}
