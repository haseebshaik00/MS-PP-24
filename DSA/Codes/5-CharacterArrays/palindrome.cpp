#include<bits/stdc++.h>
using namespace std;

string isPalindrome(char c[], int n){
    int i=0, j=n-1;
    while(i<j){
        if(c[i] == c[j]){
            i++; j--;
        }
        else
            return "false";
    }
    return "true";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c[100];
    cin.getline(c, 100);
    cout<<isPalindrome(c, strlen(c));

    return 0;
}
