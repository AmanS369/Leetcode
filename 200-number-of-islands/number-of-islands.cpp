class Solution {
public:
   int arrR[4] = {0,0,-1,1};
   int arrC[4] = {1,-1,0,0};
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>&visited,int x ,int y,int row,int col){
       visited[x][y] = true;
       for(int i=0;i<4;i++){
         int nr = x + arrR[i];
         int ny = y + arrC[i];
      if (nr >= 0 && nr < row && ny >= 0 && ny < col &&
                !visited[nr][ny] && grid[nr][ny] == '1') {
                dfs(grid, visited, nr, ny, row, col);
            }
         
       }
     

    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count =0;
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == '1' && !visited[i][j]) { dfs(grid,visited,i,j,row,col);
                count+=1;
                }
            }
        }
  return count;
    }
};