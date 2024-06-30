#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[] = "Today is a good day";
    // char* strtok(char* s, char* delimeter);
    char* ptr = strtok(s, " ");

    while(ptr != NULL){
        cout<<ptr<<endl;
        ptr = strtok(NULL, " ");
    }

    return 0;
}
