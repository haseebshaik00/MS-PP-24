#include<bits/stdc++.h>
using namespace std;

void replacePi(char c[], int i){
    if(c[i] == '\0' || c[i+1] == '\0')
        return;
    if(c[i]=='p' && c[i+1]=='i'){
        int j = i+2;
        while(c[j]!='\0')
            j++;
        for(; j>=i+2; j--)
            c[j+2] = c[j];
        c[i]='3'; c[i+1]='.'; c[i+2]='1'; c[i+3]='4';
        replacePi(c, i+4);
    }
    else
        replacePi(c, i+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c[100];
    cin.get(c, 100);
    replacePi(c, 0);
    int l=strlen(c);
    for(int i=0; i<l; i++)
        cout<<c[i];

    return 0;
}
