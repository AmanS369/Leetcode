class Solution {
public:
    static const long long MOD = 1e9 + 7;
    int dp[1002][1002];

    

    int numberOfSets(int n, int k) {
    
        for(int i=0;i<n;i++) dp[i][0] = 1;

        for(int seg = 1;seg<=k;seg++){

            long long res = 0 ;
            for(int i=1;i<n;i++){
                 res = (res + dp[i - 1][seg - 1]) % MOD;

                 dp[i][seg] = (dp[i - 1][seg] + res) % MOD;
            }
        }
         return dp[n - 1][k];
    }
};