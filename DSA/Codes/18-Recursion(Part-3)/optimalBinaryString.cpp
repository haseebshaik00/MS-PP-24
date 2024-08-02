#include<bits/stdc++.h>
using namespace std;

int binaryString(int n){
    if(n==0 || n==1)
        return n+1;
    return binaryString(n-1) + binaryString(n-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    cout<<binaryString(n)<<endl;

    return 0;
}
