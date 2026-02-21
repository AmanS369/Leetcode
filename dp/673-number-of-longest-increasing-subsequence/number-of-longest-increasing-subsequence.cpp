class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);

        mp[1] = nums.size();
        for(int i=1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[j] < nums[i]){
                  if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j]+1;
                    cnt[i] = cnt[j];
                  }else if(dp[j]+1 == dp[i]){
                    cnt[i] += cnt[j];
                  }
                }
            }
        }
        
        int maxi = *max_element(dp.begin(), dp.end());
        int result = 0;
        for (int i = 0; i < n; i++)
            if (dp[i] ==  maxi)
                result += cnt[i];

        return result;
    }
};