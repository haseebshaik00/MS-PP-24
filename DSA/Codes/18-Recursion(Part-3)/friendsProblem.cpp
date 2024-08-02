#include<bits/stdc++.h>
using namespace std;

int friends(int n){
    if(n==0 || n==1) return 1;
    if(n<0) return 0;
    return friends(n-1)+(n-1)*friends(n-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    cout<<friends(n);

    return 0;
}
