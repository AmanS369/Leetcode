class Solution {
public:
    vector<vector<int>> dp;
    vector<int> c;

    int solve(int l, int r) {
        if (r - l == 1) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int ans = INT_MAX;
        for (int i = l + 1; i < r; i++) {
            ans = min(ans,
                c[r] - c[l] + solve(l, i) + solve(i, r)
            );
        }
        return dp[l][r] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        c = cuts;
        c.push_back(0);
        c.push_back(n);
        sort(c.begin(), c.end());

        int m = c.size();
        dp.assign(m, vector<int>(m, -1));

        return solve(0, m - 1);
    }
};
