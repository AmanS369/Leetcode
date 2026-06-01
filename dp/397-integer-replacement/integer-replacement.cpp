class Solution {
public:
    unordered_map<long long, int> dp;

    int solve(long long n) {
        if (n == 1) return 0;

        if (dp.count(n))
            return dp[n];

        if (n % 2 == 0)
            return dp[n] = 1 + solve(n / 2);

        return dp[n] = 1 + min(solve(n - 1), solve(n + 1));
    }

    int integerReplacement(int n) {
        return solve((long long)n);
    }
};