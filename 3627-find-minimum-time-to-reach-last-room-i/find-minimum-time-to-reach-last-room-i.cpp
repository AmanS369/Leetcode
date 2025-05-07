#define ll long long int
class Solution {
public:
    int n = 0;
    int m = 0;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        n = moveTime.size();
        m = moveTime[0].size();

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0}); // time, x, y
        dis[0][0] = 0;

        while (!pq.empty()) {
            vector<int> top = pq.top();
      
            int time = top[0];
            int x = top[1];
            int y = top[2];
            pq.pop();

            if (x == n - 1 && y == m - 1) return time;

            if (time > dis[x][y]) continue; 

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nxttime = max(moveTime[nx][ny], time) + 1;
                    if (nxttime < dis[nx][ny]) {
                        dis[nx][ny] = nxttime;
                        pq.push({nxttime, nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};
