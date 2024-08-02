#include<bits/stdc++.h>
using namespace std;

void generateBrackets(char c[], int n, int idx, int open, int close){
    if(idx == (2*n)){
        cout<<c<<endl;
        return;
    }
    if(open<n){
        c[idx] = '(';
        generateBrackets(c, n, idx+1, open+1, close);
    }
    if(close<open){
        c[idx] = ')';
        generateBrackets(c, n, idx+1, open, close+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    char c[n+1];
    generateBrackets(c, n, 0, 0, 0);

    return 0;
}
