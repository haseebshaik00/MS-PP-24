#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int i){
    int mask = 1<<i;
    return n&mask>0 ? 1 : 0;
}

int setBit(int n, int i){
    int mask = 1<<i;
    return n|mask;
}

int clearBit(int n, int i){
    int mask = ~(1<<i);
    return n&mask;
}

int updateBit(int n, int i, int v){
    int mask = ~(1<<i);
    n = n&mask;
    return n|(v<<i);
}

int clear_i_Bits_from_zero(int n, int i){
    int a = -1;
    return (n & (a<<i));
}

int clear_i_j_Bit(int n, int i, int j){
    int i1 = (1<<i)-1;
    int j1 = -1<<(j+1);
    return (n & (i1|j1));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    cout<<getBit(n, 1)<<endl;
    cout<<setBit(n, 2)<<endl;
    cout<<clearBit(n, 3)<<endl;
    cout<<clear_i_Bits_from_zero(n, 3)<<endl;
    cout<<clear_i_j_Bit(n, 1, 3)<<endl;

    return 0;
}
