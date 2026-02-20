class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
         vector<vector<int>> grid(n, vector<int>(n, n));
        
        
        for (auto &m : mines) {
            grid[m[0]][m[1]] = 0;
        }

        for(int i=0;i<n;i++){
            int cnt =0;
            for(int j=0;j<n;j++){
              if(grid[i][j]!=0){
                 cnt+=1;
                 grid[i][j] = min(grid[i][j],cnt);
              }
              else cnt =0;

            }
            
             cnt =0;
            for(int j=n-1;j>=0;j--){
              if(grid[i][j]!=0){
                 cnt+=1;
                 grid[i][j] = min(grid[i][j],cnt);
              }
              else cnt =0;

            }
        }
        int ans =0;
        for(int j=0;j<n;j++){
            int cnt =0;
            for(int i=0;i<n;i++){
              if(grid[i][j]!=0){
                 cnt+=1;
                 grid[i][j] = min(grid[i][j],cnt);
              }
              else cnt =0;

            }
            
             cnt =0;
            for(int i=n-1;i>=0;i--){
              if(grid[i][j]!=0){
                 cnt+=1;
                 grid[i][j] = min(grid[i][j],cnt);
                 ans = max(ans,grid[i][j]);
              }
              else cnt =0;

            }
        }

        return ans;
    }
};