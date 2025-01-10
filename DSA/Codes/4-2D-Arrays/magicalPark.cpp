#include<bits/stdc++.h>
using namespace std;

/* Input
4 4 5 20
. . * .
. # . .
* * . .
. # * *

Output
Yes
13

    int i=0, j=0;
    while(i<m){
        char ch = a[i][j];
        if(s<k){
            cout<<"Fail!";
            break;
        }
        if(ch == '*') s+=5;
        else if(ch == '.') s-=2;
        else{
            j=0; i++;
            continue;
        }
        j++;
        if(j==n){j=0; i++; continue;}
        else s--;
    }
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, s, k;
    cin>>m>>n;
    char a[m][n];
    cin>>k>>s;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            char c = a[i][j];
            if(k>s){
                cout<<"no";
                return 0;
            }
            if(c == '.') s -= 2;
            else if(c == '*') s += 5;
            else break;
            if (j != n-1) s -= 1;
        }
    }
    cout<<"Yes"<<endl<<s;

    return 0;
}
