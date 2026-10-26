class Solution {
public:
    int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int countIslands(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));

        int ans = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (grid[i][j] != 0 && !vis[i][j]) {
                    long long temp = 0;
                    queue<pair<int, int>> q;

                    q.push({i, j});
                    vis[i][j] = true;

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        temp += grid[x][y];

                        for (int z = 0; z < 4; z++) {
                            int nx = x + arr[z][0];
                            int ny = y + arr[z][1];

                            if (nx >= 0 && nx < row &&
                                ny >= 0 && ny < col &&
                                grid[nx][ny] != 0 &&
                                !vis[nx][ny]) {

                                vis[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }

                    if (temp % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};