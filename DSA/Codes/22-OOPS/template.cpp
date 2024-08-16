#include<bits/stdc++.h>
using namespace std;

template <typename T>
int searchIt(T a[], int n, T k){
    for(int i=0; i<n; i++)
        if(a[i] == k)
            return i;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[] = {1, 2, 3, 4, 5};
    string b[]={"Haseeb", "hat", "af"};
    int n=5, m=3;
    string s="hat";
    cout<<searchIt(a, n, 3)<<endl;
    cout<<searchIt(b, m, s)<<endl;


    return 0;
}
