#include<bits/stdc++.h>
using namespace std;

char phone[][5] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void phoneKeyboard(char c[], char output[], int i, int j){
    if(c[i] == '\0'){
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }

    int digit = (c[i] - '0');
    if(digit == 0 || digit == 1) phoneKeyboard(c, output, i+1, j);
    for(int k=0; phone[digit][k]!='\0'; k++){
        output[j] = phone[digit][k];
        phoneKeyboard(c, output, i+1, j+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c[100], out[100];
    cin.get(c, 100);
    phoneKeyboard(c, out, 0, 0);

    return 0;
}
