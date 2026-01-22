class Solution {
public:
   int dp[40001][3];
    int solve(vector<int>& nums , int index , int mod){
        if(index >=nums.size()){
            if(mod  == 0) return mod;
            return INT_MIN;
        }
        //dp tell if adding this number whith remainder , can it give a valid cost or not
        if(dp[index][mod]!=-1) return dp[index][mod];
        int pick = nums[index]+ solve(nums,index+1,(mod + nums[index]) % 3);
        int noPick = noPick = solve(nums,index+1,mod);
        return dp[index][mod] = max(pick,noPick);

    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0);
    }
};