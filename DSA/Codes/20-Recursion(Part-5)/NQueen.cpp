#include<bits/stdc++.h>
using namespace std;

int n=4;

bool canKeep(int chess[][10], int n, int i, int j){
    for(int k=0; k<i; k++){
        if(chess[k][j])
            return false;
    }
    int x=i, y=j;
    // left diagonal
    while(x>=0 && y>=0){
        if(chess[x][y])
            return false;
        x--;y--;
    }
    x=i; y=j;
    // right diagonal
    while(x>=0 && y<n){
        if(chess[x][y])
            return false;
        x--;y++;
    }
    return true;
}

bool nQueen(int chess [][10], int n, int i){
    if(i==n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(chess[i][j]) cout<<"Q ";
                else cout<<"_ ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
    for(int j=0; j<n; j++){
        if(canKeep(chess, n, i, j)){
            chess[i][j] = 1;
            bool nextQueen = nQueen(chess, n, i+1);
            if(nextQueen) return true;
            chess[i][j] = 0;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int chess[10][10] = {0};
    nQueen(chess, n, 0);

    return 0;
}
