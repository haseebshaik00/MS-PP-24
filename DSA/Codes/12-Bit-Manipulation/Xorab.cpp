#include<bits/stdc++.h>
using namespace std;

int xorAB(int a){
    if(a%4 == 1) return 1;
    if(a%4 == 2) return a+1;
    if(a%4 == 3) return 0;
    else return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin>>a>>b;
    cout<<(xorAB(a-1)^xorAB(b))<<endl;

    return 0;
}
