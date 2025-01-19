class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int row = height.size();
        int col = height[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0]; 
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                    pq.push({height[i][j], i, j});  
                    visited[i][j] = true;
                }
            }
        }

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int water = 0;
        
        while(!pq.empty()) {

            int value = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx < 0 || nx >= row || ny < 0 || ny >= col || visited[nx][ny]) continue; 
                if(value - height[nx][ny] > 0) {
                    water += (value - height[nx][ny]);
                    pq.push({value, nx, ny});
                } else {
                    pq.push({height[nx][ny], nx, ny});
                }
                visited[nx][ny] = true;
            }
        }

        return water;
    }
};
