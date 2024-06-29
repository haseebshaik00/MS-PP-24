#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, currentLength=0, maxLength= INT_MIN;
    cin>>n;
    cin.get();
    char c[100], d[100];
    for(int i=0; i<n; i++){
        cin.getline(c, 100);
        currentLength = strlen(c);
        if( currentLength > maxLength ){
            maxLength = currentLength;
            strcpy(d, c);
        }
    }
    cout<<d<<" "<<maxLength;

    return 0;
}
