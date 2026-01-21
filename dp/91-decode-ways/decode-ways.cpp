class Solution {
public:
    int dp[101];
    int solve(int i ,string s){
        if(i >= s.size()) return 1;
        int ans =0;
        int temp = s[i] - '0';
        if(dp[i]!=-1) return dp[i];
        if(temp >=1 && temp <=9 ) ans += solve(i+1,s);
        if (i + 1 < s.size()) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26)
            ans += solve(i + 2, s);
         }

        return dp[i] = ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};