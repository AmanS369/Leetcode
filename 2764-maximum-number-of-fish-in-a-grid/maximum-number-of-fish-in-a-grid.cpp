class Solution {
public:
    int row, col;
    int dir_x[4] = {-1, 1, 0, 0};
    int dir_y[4] = {0, 0, -1, 1};

    int dfs(vector<vector<int>>& grid, int i, int j) {
      
        if (i < 0 || i >= row || j < 0 || j >= col || !grid[i][j]) return 0;


        int sum = grid[i][j];
        grid[i][j] = 0;

       
        for (int k = 0; k < 4; k++) {
            sum += dfs(grid, i + dir_x[k], j + dir_y[k]);
        }

        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
      
        if (grid.empty() || grid[0].empty()) return 0;

        row = grid.size();
        col = grid[0].size();
        int ans = 0;


        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};
