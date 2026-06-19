class Solution {
public:
    vector<vector<int>> dp;
    vector<int> nums;

    int solve(int i, int del) {

        if(i == 0) {
            if(del == 0) return nums[0];
            return -1e9;
        }

        if(dp[i][del] != -1)
            return dp[i][del];

        int ans;

        if(del == 0) {

            ans = max(
                nums[i],
                nums[i] + solve(i - 1, 0)
            );

        } else {

            ans = max(
                nums[i] + solve(i - 1, 1),
                solve(i - 1, 0)
            );
        }

        return dp[i][del] = ans;
    }

    int maximumSum(vector<int>& arr) {

        nums = arr;
        int n = arr.size();

        dp.assign(n, vector<int>(2, -1));

        int ans = arr[0];

        for(int i = 0; i < n; i++) {
            ans = max(ans, solve(i, 0));
            ans = max(ans, solve(i, 1));
        }

        return ans;
    }
};