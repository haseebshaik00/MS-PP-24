#include<bits/stdc++.h>
using namespace std;

void removeDup(char a[], int n){
    int i=0, j=1;
    while(j != '\0'){
        if(a[i] == a[j]) j++;
        else a[++i] = a[j];
    }
    a[++i] = '\0';
}

// User function template for C++
string removeDuplicates(string &s) {
    unordered_map<char, bool> m;
    int n = s.length(); string ans = "";
    for(auto x:s){
        if(!m[x]){
            ans += x;
            m[x] = true;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // sorted arrays
    char c[100];
    cin.getline(c, 100);
    removeDup(c, strlen(c));
    cout<<c<<endl;

    return 0;
}
