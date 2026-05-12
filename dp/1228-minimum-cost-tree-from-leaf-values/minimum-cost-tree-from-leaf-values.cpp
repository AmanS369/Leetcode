class Solution {
public:

    int solve(int i , int j,vector<int>& arr,  vector<vector<int>> &dp,vector<vector<int>> &maxi){
        if(i==j) return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
            int ans = INT_MAX;
        
        for(int k = i; k < j; k++) {

            int left  = solve(i, k, arr, dp, maxi);
            int right = solve(k + 1, j, arr, dp, maxi);

            int rootCost =
                maxi[i][k] * maxi[k + 1][j];

            ans = min(ans,
                      left + right + rootCost);
        }
         return dp[i][j] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> dp(n,
            vector<int>(n, -1));

        // max value in every interval
        vector<vector<int>> maxi(n,vector<int>(n, 0));

        for(int i = 0; i < n; i++) {

            maxi[i][i] = arr[i];

            for(int j = i + 1; j < n; j++) {
                maxi[i][j] =
                    max(maxi[i][j - 1], arr[j]);
            }
        }

        return solve(0, n - 1, arr, dp, maxi);

    }
};