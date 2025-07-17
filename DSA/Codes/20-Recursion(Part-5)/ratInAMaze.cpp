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

// GFG Solution
class Solution {
  public:
    vector<string> ans;
    string curr="";
    int n;
    
    void solveMaze(vector<vector<int>>& maze, int i, int j, char X){
        // add push here to avoid pushing in the base case
        if(i==n-1 && j==n-1){
            curr.push_back(X);
            ans.push_back(curr.substr(1, curr.length()-1));
            curr.pop_back();
            return;
        }
        if(i>=n || j>=n || i<0 || j<0 || maze[i][j]==0 || maze[i][j]==-1) return;
        maze[i][j] = -1;
        curr.push_back(X);
        solveMaze(maze, i-1, j, 'U');
        solveMaze(maze, i+1, j, 'D');
        solveMaze(maze, i, j-1, 'L');
        solveMaze(maze, i, j+1, 'R');
        maze[i][j] = 1;
        curr.pop_back();
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        n = maze.size();
        solveMaze(maze, 0, 0, 'X');
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char maze [10][10]= {"0000", "00X0", "000X", "0X00"};
    int output[10][10]={0};
    if(!ratMaze(maze, output, 0, 0)) cout<<"Not Possible!"<<endl;
    cout<<"Total ways = "<<cnt<<endl;

    return 0;
}
