#include<bits/stdc++.h>
using namespace std;

string words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printWords(int n){
    if(n==0)
        return;
    printWords(n/10);
    cout<<words[n]<<" ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    printWords(n);

    return 0;
}