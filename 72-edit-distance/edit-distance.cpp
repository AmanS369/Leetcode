class Solution {
public:

int dp[502][502]; 

int solve(string &str1, string &str2, int m, int n) {

    if (m == 0) return n;
    if (n == 0) return m;

  
    if (dp[m][n] != -1) return dp[m][n];

    if (str1[m - 1] == str2[n - 1]) {
        dp[m][n] = solve(str1, str2, m - 1, n - 1);
    } else {
    
        dp[m][n] = 1 + min({
            solve(str1, str2, m, n - 1),    // Insert
            solve(str1, str2, m - 1, n),    // Remove
            solve(str1, str2, m - 1, n - 1) // Replace
        });
    }
    return dp[m][n];
}


    int minDistance(string str1, string str2) {

            memset(dp, -1, sizeof(dp));

   
    return solve(str1, str2, str1.length(), str2.length());
        
    }
};