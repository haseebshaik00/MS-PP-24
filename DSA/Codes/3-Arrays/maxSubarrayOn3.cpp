#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, left=-1, right=-1, currentSum=0, sum = INT_MIN;
    cin>>n;
    int a[n];
    memset(a, 0, n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            currentSum=0;
            for(int k=i; k<=j; k++){
                currentSum += a[k];
            }
            if(currentSum > sum){
                sum = currentSum;
                left = i;
                right = j;
            }
        }
    }
    cout<<"From i to j "<<left<<" "<<right<<" Sum = "<<sum<<endl;

    return 0;
}
