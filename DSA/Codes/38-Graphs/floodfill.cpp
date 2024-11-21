int n, m; 
    void floodFillHelper(int r, int c, vector<vector<int>>& image, int color, int originalColor){
        if(r<0 || r>=n || c<0 || c>=m || image[r][c] != originalColor)
            return;
        image[r][c] = color;
        int dx[]={-1, 0, 1, 0}, dy[]={0, -1, 0, 1};
        for(int k=0; k<4; k++){
            int nx=r+dx[k], ny=c+dy[k];
            floodFillHelper(nx, ny, image, color, originalColor);
        }
    }
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n=image.size();
        m=image[0].size();
        int originalColor = image[sr][sc];
        if (originalColor != newColor) {
            floodFillHelper(sr, sc, image, newColor, originalColor);
        }
        return image;
    }