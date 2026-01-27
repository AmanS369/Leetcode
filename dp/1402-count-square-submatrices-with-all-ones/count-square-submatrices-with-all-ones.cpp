class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>>dp(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==1 ){
                   if(i>=1 && j >=1) dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                   else dp[i][j] = 1;
                }
            }
        }

        int ans =0;
        for(auto i: dp){
            for(auto j:i){
                ans+=j;
            }
        }

        return ans;

    }
};