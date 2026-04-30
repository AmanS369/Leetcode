class Solution {
public:
    int r, c;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, vector<vector<int>>& grid, int k) {
        
        if (i >= r || j >= c) return INT_MIN;

       
        if (k == 0 && (grid[i][j] == 1 || grid[i][j] == 2)) {
            return INT_MIN;
        }

        // Destination
        if (i == r - 1 && j == c - 1) {
            if (grid[i][j] == 1 || grid[i][j] == 2) {
                if (k > 0) return grid[i][j];
                else return INT_MIN;
            }
            return grid[i][j];
        }

        if (dp[i][j][k] != -1) return dp[i][j][k];

        int cost = grid[i][j];
        int newK = k;

        if (grid[i][j] == 1 || grid[i][j] == 2) {
            newK--;
        }

        int right = solve(i, j + 1, grid, newK);
        int down  = solve(i + 1, j, grid, newK);

        int best = max(right, down);

        if (best == INT_MIN) return dp[i][j][k] = INT_MIN;

        return dp[i][j][k] = cost + best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        r = grid.size();
        c = grid[0].size();

        dp = vector<vector<vector<int>>>(r, vector<vector<int>>(c, vector<int>(k + 1, -1)));

        int ans =  solve(0, 0, grid, k);
        if(ans<0) return -1;
        return ans;
    }
};