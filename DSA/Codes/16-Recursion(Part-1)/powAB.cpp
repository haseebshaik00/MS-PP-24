#include<bits/stdc++.h>
using namespace std;

int powAB(int a, int b){
    if(b==1)
        return a;
    else if(b%2 == 0)
        return powAB(a*a, b/2);
    else return a * powAB(a*a, (b-1)/2);
}

int powABloop(int a, int b){
    if(b==1)
        return a;
    return a*powABloop(a, b-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin>>a>>b;
    cout<<powAB(a, b)<<endl; //O(log(base2)N)
    cout<<powABloop(a, b)<<endl; //O(N)

    return 0;
}
