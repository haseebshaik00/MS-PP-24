#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s1="geeks for geeks";
	string s2="geeks";

	size_t found = s1.find(s2);

	if(found != string::npos)
        cout<<found<<endl;
    else cout<<"-1"<<endl;

    cout<<s1.find(s2, found+1)<<endl;

	return 0;
}
