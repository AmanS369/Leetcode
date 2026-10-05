class Solution {
public:
    int dp[10001][51];
    int n;

    int solve(vector<int>& nums, int k, int i) {

        if (k == 1) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
            }
            return sum;
        }

        if (dp[i][k] != -1)
            return dp[i][k];

        int res = INT_MAX;
        int sum = 0;

        for (int j = i; j <= n - k; j++) {

            sum += nums[j];

            int remaining = solve(nums, k - 1, j + 1);

            int ans = max(sum, remaining);

            res = min(res, ans);
        }

        return dp[i][k] = res;
    }

    int splitArray(vector<int>& nums, int k) {
        n = nums.size();

        memset(dp, -1, sizeof(dp));

        return solve(nums, k, 0);
    }
};