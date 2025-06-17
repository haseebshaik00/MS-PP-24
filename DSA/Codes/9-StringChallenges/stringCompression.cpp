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


// gfg question 
// User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int s=S.length(), t=T.length(), j=0;
        string x = "";
        for(int i=0; i<t; i++){
            if(T[i]<='9' && T[i]>='0') x += T[i];
            else{
                if(x != "") j += stoi(x);
                if(T[i] != S[j]) return 0;
                j++; x="";
            }
        }
        if(x != "") j += stoi(x);
        return j==s;
    }
};


//gfg question
int checkCompressed(string S, string T) {
        int j = 0, i = 0;
        while (i < T.length()) {
            if (isdigit(T[i])) {
                int c = 0;
                while (i < T.length() && isdigit(T[i])) {
                    c = c * 10 + (T[i] - '0');
                    i++;
                }
                j += c;
            } else {
                if (j >= S.length() || S[j] != T[i]) 
                    return 0;
                i++; j++;
            }
        }
        return j == S.length();
    }