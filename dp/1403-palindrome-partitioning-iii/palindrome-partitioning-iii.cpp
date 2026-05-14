class Solution {
public:

    int dp[101][101];

    int palindromeCost(string &s, int i, int j){

        int ans = 0;

        while(i < j){

            if(s[i] != s[j])
                ans++;

            i++;
            j--;
        }

        return ans;
    }

    int solve(int i, int k, string &s){

        int n = s.size();

        // valid partition
        if(i == n && k == 0)
            return 0;

        // invalid
        if(i == n || k == 0)
            return 1e9;

        if(dp[i][k] != -1)
            return dp[i][k];

        int ans = 1e9;

        for(int p = i; p < n; p++){

            int cost = palindromeCost(s, i, p);

            ans = min(
                ans,
                cost + solve(p + 1, k - 1, s)
            );
        }

        return dp[i][k] = ans;
    }

    int palindromePartition(string s, int k) {

        memset(dp, -1, sizeof(dp));

        return solve(0, k, s);
    }
};