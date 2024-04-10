#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, key, flag=0;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>key;
    for(int i=0; i<n; i++){
        if(a[i] == key){
         cout<<"Position = "<<i+1<<endl;
         flag=1;
        }
        else continue;
    }
    if(flag == 0) cout<<"Not Present"<<endl;
    return 0;
}
