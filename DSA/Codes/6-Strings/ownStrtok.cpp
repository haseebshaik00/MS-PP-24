#include<bits/stdc++.h>
using namespace std;

char* myStrtok( char* s, char d){
    static char* input = NULL;

    // If s is not NULL, it means it's the first call, so input is set to s.
    // If input is already NULL (end of the string), return NULL.
    if(s != NULL)
        input = s;
    if(input == NULL)
        return NULL;

    char* output = new char[strlen(input)+1];
    int i=0;
    for(; input[i] != '\0'; i++){
        if(input[i] != d){
            output[i] = input[i];
        }
        else{
            output[i] = '\0';
            cout<<"-"<<input<<endl;
            input = input + i + 1;
            cout<<"-"<<input<<endl;
            return output;
        }
    }
    output[i] = '\0';
    input = NULL;
    return output;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[100] = "Today is a good day";
    char *ptr = myStrtok(s, ' ');
    cout<<ptr<<endl;
    while(ptr != NULL){
        ptr = myStrtok(NULL, ' ');
        cout<<ptr<<endl;
    }

    return 0;
}