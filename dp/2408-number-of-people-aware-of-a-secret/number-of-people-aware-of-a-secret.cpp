class Solution {
public:
static constexpr long long MOD = 1e9 + 7;  

    vector<long long> dp;
    long long solve(int k, int n, int forget, int delay) {
        long long ans = (k + forget > n) ? 1 : 0;

        if(dp[k] != -1)
            return dp[k];

        for(int i = k + delay; i < min(k + forget, n + 1); i++) {
            ans =  (ans + solve(i, n, forget, delay))%MOD;
        }

        return dp[k]=ans;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
          dp.assign(n + 1, -1);
        return solve(1, n, forget, delay);
    }
};