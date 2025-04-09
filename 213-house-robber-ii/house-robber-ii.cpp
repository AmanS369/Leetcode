class Solution {
public: 
    int dp[101][2];

    int solve(vector<int>& nums, int index, bool first) {
        if(index >= nums.size()) return 0;
        if(index == nums.size()-1 && first) return 0;

        if(dp[index][first] != -1) return dp[index][first];

        int pick = 0, not_pick = 0;

 
        if(index == 0) {
            pick = nums[index] + solve(nums, index + 2, true);
        } else {
            pick = nums[index] + solve(nums, index + 2, first);
        }

        not_pick = solve(nums, index + 1, first);

        return dp[index][first] = max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, false);
    }
};
