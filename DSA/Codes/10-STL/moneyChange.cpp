#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int money[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
    int n, sum =0, m=0, ans=0;
    int l = sizeof(money)/sizeof(money[0]);
    int *lb;
    cin>>n;
    m=n;
    while(m>0){
        lb = upper_bound(money, money+l, m);
        sum += *(lb--);
        m -= *(lb--);
        ans++;
    }
    cout<<ans;

    return 0;
}
