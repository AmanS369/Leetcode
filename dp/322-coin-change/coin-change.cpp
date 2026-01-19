class Solution {
public:
    long dp[14][10001];
    long solve(int i, int sum, vector<int>& coins) {
    if (sum == 0) return 0;
    if (i < 0 || sum < 0) return INT_MAX;
    if(dp[i][sum]!=-1) return dp[i][sum];
    long take = solve(i, sum - coins[i], coins);
    if (take != INT_MAX) take += 1;

    long skip = solve(i - 1, sum, coins);

    return  dp[i][sum] = min(take, skip);
}

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        long ans  = solve(coins.size()-1,amount,coins);
        return ans == INT_MAX ? -1 :ans;
    }
};