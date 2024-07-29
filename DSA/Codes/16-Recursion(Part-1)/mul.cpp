#include<bits/stdc++.h>
using namespace std;

int mul(int a, int b){
    if(b==1)
        return a;
    return a+mul(a, b-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin>>a>>b;
    cout<<mul(a, b)<<endl;

    return 0;
}
