#include<bits/stdc++.h>
using namespace std;

int tile(int n){
    if(n<=3)
        return 1;
    return tile(n-1)+tile(n-4);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    cout<<tile(n)<<endl;

    return 0;
}
