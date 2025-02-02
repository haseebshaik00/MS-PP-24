#include<bits/stdc++.h>
using namespace std;

void readLine(char a[], int n, char c){
    char ch;
    cin.get(ch); //ch = cin.get() -- take input of the first character
    int i = 0;
    while(ch != c){
        a[i] = ch;
        i++;
        if(i == n-1) break;
        ch = cin.get();
    }
    a[i] = '\0';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char a[1000];
    cin.getline(a, 1000); // takes sentences as default delimeter is '\n'
    cin.getline(a, 1000, '$');
    cout<<a<<endl;;
    readLine(a, 100, '#');
    cout<<a<<endl;

    return 0;
}
