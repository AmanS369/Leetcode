class Solution {
public:
    int dp[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int row, int col) {
        vis[i][j] = true;

        for(int z=0; z<4; z++){
            int nx = i + dp[z][0];
            int ny = j + dp[z][1];

            if(nx>=0 && ny>=0 && nx<row && ny<col && !vis[nx][ny] && grid[nx][ny]==1){
                dfs(grid, vis, nx, ny, row, col);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> vis(row, vector<bool>(col, false));

        // 1. Traverse boundaries
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 || j==0 || i==row-1 || j==col-1){
                    if(grid[i][j]==1 && !vis[i][j]){
                        dfs(grid, vis, i, j, row, col);
                    }
                }
            }
        }

        // 2. Count remaining land
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }

        return count;
    }
};
