#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,flag=-1;
    cin>>n;
    int a[n];
    memset(a, n, 0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>k;
    for(int i=0; i<n; i++)
        if(a[i] == k)
            flag=i;
    flag != -1 ? cout<<"Present at "<< (flag+1) <<endl : cout<<"Not Present"<<endl;

    return 0;
}
