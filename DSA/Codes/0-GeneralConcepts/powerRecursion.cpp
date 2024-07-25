#include<bits/stdc++.h>
using namespace std;

int powerab(int a, int b){
    if(b==0) return 1;
    if(b%2==0) return powerab(a*a, b/2);
    else return a*powerab(a*a, (b-1)/2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin>>a>>b;
    cout<<powerab(a, b)<<endl;

    return 0;
}
