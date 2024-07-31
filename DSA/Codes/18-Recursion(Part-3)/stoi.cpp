#include<bits/stdc++.h>
using namespace std;

int stoii(string n, int l){
    if(l==-1)
        return 0;
    return (n[l]-'0') + stoii(n, l-1)*10;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin>>n;
    int l = n.length();
    cout<<stoii(n, l-1);

    return 0;
}
