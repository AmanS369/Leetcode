class Solution {
public:
    int dp[1001][1001];
    int solve(int idx,vector<int>& nums, int target){
        if(target == 0) return 0;
        if(idx >=nums.size()) return INT_MIN;
        

        if(dp[idx][target]!=-1) return dp[idx][target];

        int pick = INT_MIN;
        if(target - nums[idx] >=0){
            //pick
            pick = 1 + solve(idx+1,nums,target - nums[idx]);
        }

        return dp[idx][target] = max(solve(idx+1,nums,target),pick);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,nums,target);
        return ans<0?-1:ans;
    }
};


// class Solution {
// public:
//     int dp[1001][1001];
    
//     int solve(int idx, vector<int>& nums, int target){
//         if(target == 0) return 0;
//         if(idx >= nums.size()) return -1000000;  // impossible
        
//         if(dp[idx][target] != -1) return dp[idx][target];
        
//         int notPick = solve(idx+1, nums, target);
//         int pick = -1000000;
        
//         if(target - nums[idx] >= 0){
//             pick = 1 + solve(idx+1, nums, target - nums[idx]);
//         }
        
//         return dp[idx][target] = max(pick, notPick);
//     }
    
//     int lengthOfLongestSubsequence(vector<int>& nums, int target) {
//         memset(dp, -1, sizeof(dp));
//         int ans = solve(0, nums, target);
//         return ans < 0 ? -1 : ans;
//     }
// };
