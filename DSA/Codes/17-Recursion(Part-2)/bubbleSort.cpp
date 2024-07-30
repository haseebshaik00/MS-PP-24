#include<bits/stdc++.h>
using namespace std;

void bubbleSortRec(int a[], int n, int j){
    if(n==1) // i loop of n-1 iterations
        return;
    if(j == n-1) // i loop for swapping
        // until the last element gets the max no
        // single pass of current array is done
        return bubbleSortRec(a, n-1, 0);
    if(a[j] > a[j+1])
        swap(a[j], a[j+1]);
    bubbleSortRec(a, n, j+1); // j loop for 1 to n-1-i
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    memset(a, 0, n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    bubbleSortRec(a, n, 0);
    for(auto x:a)
        cout<<x<<" ";

    return 0;
}
