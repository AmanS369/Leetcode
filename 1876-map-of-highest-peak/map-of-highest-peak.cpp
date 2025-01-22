class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();
        vector<vector<int>> ans(row, vector<int>(col, -1));
        queue<pair<int, pair<int, int>>> q;

      
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({0, {i, j}});
                }
            }
        }

        
        int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        
       
        while (!q.empty()) {
            int value = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
               
                if (nx >= 0 && ny >= 0 && nx < row && ny < col && ans[nx][ny] == -1) {
                    ans[nx][ny] = value + 1;
                    q.push({value + 1, {nx, ny}});
                }
            }
        }

        return ans;
    }
};
