#include<bits/stdc++.h>
using namespace std;

set<string> s;

void permut(char c[], int i){
    if(c[i]=='\0'){
        string str(c);
        s.insert(str);
        return;
    }
    for(int j=i; c[j]!='\0'; j++){
        swap(c[i], c[j]);
        permut(c, i+1);
        swap(c[i], c[j]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c[10];
    cin>>c;
    permut(c, 0);
    // already sorted
    for(auto x:s)
        cout<<x<<" ";

    return 0;
}
