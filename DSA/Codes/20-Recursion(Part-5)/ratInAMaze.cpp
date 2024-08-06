#include<bits/stdc++.h>
using namespace std;

int n=4, m=4, cnt=0;

bool ratMaze(char maze[10][10], int output[10][10], int i, int j){
    if(i==m-1 && j==n-1){
        output[i][j] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<output[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cnt++;
        return true;
    }
    if(i>=m || j>=n || maze[i][j]=='X')
        return false;
    output[i][j] = 1;
    bool right = ratMaze(maze, output, i, j+1);
    bool down = ratMaze(maze, output, i+1, j);
    if(right || down) return true;
    output[i][j] = 0;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char maze [10][10]= {"0000", "00X0", "000X", "0X00"};
    int output[10][10]={0};
    if(!ratMaze(maze, output, 0, 0)) cout<<"Not Possible!"<<endl;
    cout<<"Total ways = "<<cnt<<endl;

    return 0;
}
