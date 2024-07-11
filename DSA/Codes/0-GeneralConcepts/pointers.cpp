#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 10;
    int b = 20;
    char ch = 'A';

    // declaration and initialization
    int *aptr = &a;
    cout<<aptr<<endl;

    // reassign
    aptr = &b;
    cout<<aptr<<endl;

    // for char
    char *cptr = &ch;
    cout<<(void*)&cptr<<" "<<(int*)&cptr<<endl;

    // NULL pointer
    int *ptr1 = NULL;
    cout<<ptr1<<endl;

    return 0;
}
