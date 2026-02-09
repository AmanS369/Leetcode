class Solution {
public:
 int dp[4][2] = {
        {-1,0},{1,0},{0,-1},{0,1}
    };
    int minimumEffortPath(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> q;

        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));

        q.push({0,{0,0}});
        dist[0][0] = 0;
        int ans =INT_MAX;
        while(!q.empty()){
            int heighDiff = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second; 
            q.pop();

            if(x==row-1 && y==col-1) return heighDiff;

            for(int i=0;i<4;i++){
                int nx = x + dp[i][0];
                int ny = y + dp[i][1];
                if(nx>=0 && ny>=0 && nx<row && ny<col){
                 int newEff = max(heighDiff, abs(grid[nx][ny]-grid[x][y]));
                 if(newEff < dist[nx][ny]){
                    dist[nx][ny] = newEff;
                    q.push({newEff,{nx,ny}});
                 }
                }
                
            }
        }

        return 0;
    }
};