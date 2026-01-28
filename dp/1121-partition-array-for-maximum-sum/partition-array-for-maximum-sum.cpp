class Solution {
public:
    int dp[500];
    int solve(int i,int n,vector<int>& arr, int k){
        if(i >= n) return 0;
        int ans =0;
        if(dp[i]!=-1) return dp[i];
        int maxi =-1;
        int p = i;
 
        while(p < n && p < i + k){
            maxi = max(arr[p],maxi);
            ans = max(ans,((p-i+1)*maxi) + solve(p+1,n,arr,k) );
            p++;
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,arr.size(),arr,k);
    }
};