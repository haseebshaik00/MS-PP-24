#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c[][12] = {{'h','i','\0'}, {'y','o','\0'}};
    char d[10] = "haseeb";
    // char a[] - not allowed should define size;
    // char c[2] = "zoom"; - not allowed
    cout<<c[0]<<" "<<c[0][1]<<" "<<d<<" "<<d[2]<<endl;

    char s[10], r[10];
    cin.get(s, 10);
    cin.get(); //cin.ignore();
    cin.get(r, 10);
    cout<<s<<" "<<r<<endl;

    cin.ignore();
    char x[10], y[10];
    cin.getline(x, 10);
    cin.getline(y, 20);
    cout<<x<<" "<<y<<endl;

    char aa[100][100];
    int n;
    cin>>n;
    cin.get();
    for(int i=0; i<n; i++)
        cin.getline(aa[i], 100);
    for(int i=0; i<n; i++)
        cout<<aa[i]<<" ";

    char b[] = {'h', 'i', '\0'}; // sizeof = 3 ; strlen(b)=2;
    char b[] = "ji"; // delimeter is automatically appended in the end hence; sizeof = 3 ; strlen(b)=2;
    // cout<<b<<endl; - prints address of b



    return 0;
}
