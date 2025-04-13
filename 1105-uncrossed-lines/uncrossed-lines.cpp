class Solution {
public:
int dp[501][501];
unordered_map<int,vector<int>>mp;
    int solve(int index,int min_y,vector<int>&nums1){
        if(index >= nums1.size()) return 0;
        if(dp[index][min_y+1]!=-1) return dp[index][min_y+1];
        int ans=0;
        for(auto i : mp[nums1[index]]){
            if(i > min_y){
                ans = max(ans,1 + solve(index+1,i,nums1));
            }
        }
        ans = max(ans,solve(index+1,min_y,nums1));

        return dp[index][min_y+1] = ans;

    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums2.size();i++) mp[nums2[i]].push_back(i);
        memset(dp, -1, sizeof(dp));
        return solve(0,-1,nums1);
    }
};