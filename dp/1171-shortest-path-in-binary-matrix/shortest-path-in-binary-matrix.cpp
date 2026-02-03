class Solution {
public:
   int dp[8][2] = {
        {-1,0},{1,0},{0,-1},{0,1},
        {1,1},{1,-1},{-1,-1},{-1,1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if(grid[0][0]==1 || grid[row-1][col-1]==1) return -1;

        queue<pair<int,pair<int,int>>> q;
        vector<vector<bool>> vis(row,vector<bool>(col,false));

        q.push({1,{0,0}});
        vis[0][0] = true;

        while(!q.empty()){
            int length = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second; 
            q.pop();

            if(x==row-1 && y==col-1) return length;

            for(int i=0;i<8;i++){
                int nx = x + dp[i][0];
                int ny = y + dp[i][1];

                if(nx>=0 && ny>=0 && nx<row && ny<col &&
                   !vis[nx][ny] && grid[nx][ny]==0){
                    vis[nx][ny] = true;
                    q.push({length+1,{nx,ny}});
                }
            }
        }

        return -1;
    }
};
