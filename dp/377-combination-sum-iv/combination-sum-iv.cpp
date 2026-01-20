class Solution {
public:
    int dp[1001];

    int solve(int amount, vector<int>& nums) {
        if (amount == 0) return 1;
        if (amount < 0) return 0;
        if (dp[amount] != -1) return dp[amount];

        int ans = 0;
        for (int x : nums) {
            ans += solve(amount - x, nums);
        }
        return dp[amount] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(target, nums);
    }
};
