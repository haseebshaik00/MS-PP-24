#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    int n= s.length(), i=0, j=1, c=1;
    while(i < n){
        if(s[i] == s[j]){
            j++; c++;
        }
        else{
            cout<<s[i]<<c;
            i=j; j++;
            c=1;
        }
    }

    return 0;
}