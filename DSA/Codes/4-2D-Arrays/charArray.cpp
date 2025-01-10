#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char a[10] = {'h', 'e', 'y', '\0'}; // delimeter compulsory 
    char b[10] = "haseeb"; // no need to give delimeter here;
    char c[][12] = {{'h','i','\0'}, {'y','o','\0'}};
    char d[][10] = {"haseeb", "ateeq"};
    cout<<c[0][0]<<c[0]<<" "<<d[0]<<d[0][1];

    return 0;
}
