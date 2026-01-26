class Solution {
public:
    int dp[302][302];
    int solve(vector<int>& arr, int i, int j) {
        // no balloon between i and j
        if (j <= i + 1) return 0;

        int ans = 0;
        if(dp[i][j]!=-1) return dp[i][j];
        // k is the last balloon to burst
        for (int k = i + 1; k < j; k++) {
            int coins = arr[i] * arr[k] * arr[j]
                        + solve(arr, i, k)
                        + solve(arr, k, j);

            ans = max(ans, coins);
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> tmp;
        tmp.push_back(1);
        for (int x : nums) tmp.push_back(x);
        tmp.push_back(1);
        memset(dp,-1,sizeof(dp));
        return solve(tmp, 0, tmp.size() - 1);
    }
};
