class Solution {
public:
    int dp[101][101];
    int solve(string s , int i ,int j){
        if(i==j) return 1;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int k = i+1;
        while(k<=j && s[k] == s[i]) k++;
        if(k == j+1) return dp[i][j] = 1;
        int ans1 = 1 + solve(s,k,j);
        int ans2 = INT_MAX;
        for(int x = k ;x<=j;x++){
            if(s[x] == s[i]) {
             ans2 = min(ans2,solve(s,k,x-1) + solve(s,x,j) );
            }
        }
        return dp[i][j] = min(ans2,ans1);
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size()-1);
    }
};