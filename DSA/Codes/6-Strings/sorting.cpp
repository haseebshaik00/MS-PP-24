#include<bits/stdc++.h>
using namespace std;

bool comp(string a, string b){
    if(a.length() == b.length())
        return a<b;
    else
        return a.length() < b.length();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    string s[n];
    cin.ignore();
    for(int i=0; i<n; i++)
        getline(cin, s[i]);
    sort(s, s+n, comp);
    for(int i=0; i<n; i++)
        cout<<s[i]<<endl;

    return 0;
}
