#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    int largest= INT_MIN, smallest= INT_MAX; //included in <climits> library
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++){
        largest= max(a[i], largest); //func included in algorithm library
        smallest= min(a[i], smallest); //func included in algorithm library
    }
    cout<<largest<<" "<<smallest<<endl;

    return 0;
}
