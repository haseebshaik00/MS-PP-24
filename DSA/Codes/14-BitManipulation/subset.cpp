#include<bits/stdc++.h>
using namespace std;

void storeSubsetInside(vector<string> &v, int n, string str){
    if(!n){
        v.push_back("");
        return;
    }
    string s = str;
    string s1= "";
    int j=0;
    while(n>0){
        int lastBit = n&1;
        if(lastBit)
            s1 += s[j];
        j++;
        n = n>>1;
    }
    v.push_back(s1);
    return;
}

void storeSubset(vector<string> &v, string s){
    int l = s.length();
    int n = pow(2, l);
    for(int i=0; i<n; i++)
        storeSubsetInside(v, i, s);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    vector<string> v;
    storeSubset(v, s);
    for(auto x: v)
        cout<<x<<" ";

    return 0;
}
