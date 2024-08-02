#include<bits/stdc++.h>
using namespace std;

void stringAcode(char c[], char output[], int i, int j){
    if(c[i]=='\0'){
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }
    int digit = c[i]-'0';
    if(digit==0) stringAcode(c, output, i+1, j);
    else{
            int digit2 = digit*10+(c[i+1]-'0');
            output[j] = 'A'+digit-1;
            stringAcode(c, output, i+1, j+1);
            if(digit2<=26 && c[i+1]!='\0'){
            output[j] = 'A'+digit2-1;
            stringAcode(c, output, i+2, j+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c[100], output[100];
    cin.get(c, 100);
    stringAcode(c, output, 0, 0);

    return 0;
}
