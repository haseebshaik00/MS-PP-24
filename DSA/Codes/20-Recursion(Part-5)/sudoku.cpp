#include <bits/stdc++.h>
using namespace std;

int n = 9;

bool canPut(int mat[10][10], int n, int i, int j, int no){
    for(int k=0; k<n; k++){
        if(mat[k][j]==no || mat[i][k]==no)
            return false;
    }
    int n2 = sqrt(n);
    int sx = (i/n2)*n2, sy=(j/n2)*n2;
    for(int x=sx; x<sx+n2; x++){
        for(int y=sy; y<sy+n2; y++)
            if(mat[x][y]==no)
                return false;
    }
    return true;
}

bool sudoku(int mat[10][10], int n, int i, int j){
    if(i==n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    if(j==n)
        return sudoku(mat, n, i+1, 0);
    if(mat[i][j] != 0)
        return sudoku(mat, n, i, j+1);
    for(int k=1; k<=9; k++){
        if(canPut(mat, n, i, j, k)){
            mat[i][j]=k;
            int putNext = sudoku(mat, n, i, j+1);
            if(putNext)
                return true;
        }
    }
    mat[i][j]=0;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mat[10][10] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                   {5, 2, 0, 0, 0, 0, 0, 0, 0},
                   {0, 8, 7, 0, 0, 0, 0, 3, 1},
                   {0, 0, 3, 0, 1, 0, 0, 8, 0},
                   {9, 0, 0, 8, 6, 3, 0, 0, 5},
                   {0, 5, 0, 0, 9, 0, 6, 0, 0},
                   {1, 3, 0, 0, 0, 0, 2, 5, 0},
                   {0, 0, 0, 0, 0, 0, 0, 7, 4},
                   {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    sudoku(mat, n, 0, 0);

    return 0;
}
