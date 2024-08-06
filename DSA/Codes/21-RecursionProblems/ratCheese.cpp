#include<bits/stdc++.h>
using namespace std;

bool ratMaze(char mat[][12], int m, int n, int i, int j){
	if(i==m-1 && j==n-1){
		mat[i][j] = '1';
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(mat[i][j]=='1') cout<<"1"<<" ";
				else cout<<"0"<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	if(i>m-1 || j>n-1 || i<0 || j<0 || mat[i][j] == 'X' || mat[i][j] == '1')
		return false;
	mat[i][j] = '1';
	bool up=false, down=false, right=false, left=false;
    down = ratMaze(mat, m, n, i+1, j);
    if(!down)
        right = ratMaze(mat, m, n, i, j+1);
    if(!down && !right)
        up = ratMaze(mat, m, n, i-1, j);
    if(!down && !right && !up)
        left = ratMaze(mat, m, n, i, j-1);
	if(right || down || up || down)
		return true;
	mat[i][j] = '0';
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin>>m>>n;
	char mat[12][12];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin>>mat[i][j];
	if(!ratMaze(mat, m, n, 0, 0)) cout<<"NO PATH FOUND";

	return 0;
}
