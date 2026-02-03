class Solution {
public:
    int dp[4][2] = {
        {-1,0},{1,0},{0,-1},{0,1}
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<pair<int,int>> rottenList;
        int fresh = 0;

        // collect initial rotten + count fresh
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 2) rottenList.push_back({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0;

        int ans = 0;

        while(!rottenList.empty()){
            vector<pair<int,int>> newRottenList;
            bool rottedThisRound = false;

            for(auto [i,j] : rottenList){
                for(int z=0; z<4; z++){
                    int nx = i + dp[z][0];
                    int ny = j + dp[z][1];

                    if(nx>=0 && ny>=0 && nx<row && ny<col && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;         
                        newRottenList.push_back({nx,ny});
                        fresh--;
                        rottedThisRound = true;
                    }
                }
            }

            if(!rottedThisRound) break;

            ans++;
            rottenList = newRottenList;
        }

        return fresh == 0 ? ans : -1;
    }
};
