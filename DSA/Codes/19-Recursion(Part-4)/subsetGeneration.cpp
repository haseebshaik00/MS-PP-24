#include<bits/stdc++.h>
using namespace std;

void subsetGen(char c[], char out[], int i, int j){
    if(c[i]=='\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    out[j] = c[i];
    subsetGen(c, out, i+1, j+1);
    subsetGen(c, out, i+1, j);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c[100];
    cin.getline(c, 100);
    char out[100];
    subsetGen(c, out, 0, 0);

    return 0;
}
