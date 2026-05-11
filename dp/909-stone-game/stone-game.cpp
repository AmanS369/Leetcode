class Solution {
public:
  int dp[501][501];

    int solve(vector<int>& nums, int i, int j){

        if(i == j)
            return nums[i];

        if(dp[i][j] != -1)
            return dp[i][j];

        int takeLeft =
            nums[i] - solve(nums,i+1,j);

        int takeRight =
            nums[j] - solve(nums,i,j-1);

        return dp[i][j] =
            max(takeLeft,takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));

        return solve(piles,0,piles.size()-1) >= 0;
    }
};