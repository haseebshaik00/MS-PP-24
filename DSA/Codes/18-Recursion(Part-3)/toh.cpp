#include<bits/stdc++.h>
using namespace std;

int countIt = 0;

void toh(int n, char src, char helper, char dest){
    if(n==0)
        return;
    toh(n-1, src, dest, helper);
    cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<endl;
    countIt++;
    toh(n-1, helper, src, dest);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    toh(n, 'A', 'B', 'C');
    cout<<"Total Steps = "<<countIt<<endl;

    return 0;
}
