#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a1 = 10;
    int b = 20;
    char ch = 'A';

    // declaration and initialization
    int *aptr = &a1;
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

    int a[] = {1, 2, 3, 4, 5};
    cout<<"a="<<a<<" ~ "<<"&a[0]="<<&a[0]<<endl; // gives address of first element

    // int *a = {1,2,3} -> not allowed
    // char *a = {'1','2','3'} -> not allowed
    char *charArray = "string"; //allowed
    char a3[] = "geeks";
	char *p3 = "geeks";
    a3[1] = 'a';
	cout<<a3<<" "<<*p3<<" "<<sizeof(*p3);
	// int *c = 2; -> not allowed

    // Refer Notes

    return 0;
}
