class Solution {
public:
    vector<int> dp;

    Solution() : dp(20, -1) {}

    int numTrees(int n) {
        if (n == 0 || n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int left = numTrees(i - 1);
            int right = numTrees(n - i);
            ans += left * right;
        }
        
        return dp[n] = ans;
    }
};
