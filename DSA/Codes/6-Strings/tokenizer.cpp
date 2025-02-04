#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // char s[] = "Today is a good day";
    // // char* strtok(char* s, char* delimeter);
    // char* ptr = strtok(s, " ");

    // while(ptr != NULL){
    //     cout<<ptr<<endl;
    //     ptr = strtok(NULL, " ");
    // }

    string s = "Haseeb is a good boy";
    char *ptr = strtok((char *)s.c_str(), " ");
    while(ptr!=NULL){
        cout<<ptr<<endl;
        ptr = strtok(NULL, " ");
    }

    return 0;
}
