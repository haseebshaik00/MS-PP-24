#include<bits/stdc++.h>
using namespace std;

int clear_i_j_Bit(int n, int i, int j){
    int i1 = (1<<i)-1;
    int j1 = -1<<(j+1);
    return (n & (i1|j1));
}

int replace_n_m_Bit(int n, int m, int i, int j){
    int n1 = clear_i_j_Bit(n, i, j);
    return (n1 | (m<<i));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=15, i=1, j=3, m=2;
    cout<<replace_n_m_Bit(n, m, i, j);

    return 0;
}
