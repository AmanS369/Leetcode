class Solution {
public:
int solve(vector<int>& prices,int buy,int index,vector<vector<int>>&dp){
   if(index>=prices.size()) return 0;
   int ans=0;
   if(dp[index][buy + 1]!=-1) return dp[index][buy + 1];
   if(buy==-1){
     ans = solve(prices,index,index+1,dp);
   }else{
    ans = max(ans,prices[index] - prices[buy] + solve(prices,-1,index+2,dp));
   }
   ans = max(ans,solve(prices,buy,index+1,dp));
   return dp[index][buy + 1] = ans;
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(prices,-1,0,dp);
    }
};