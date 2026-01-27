class Solution {
public:
    unordered_map<int,unordered_map<int,int>>mp;
    int solve(vector<int>& nums, int target ,int idx , int sum){
        if(idx == nums.size()){
            if ( sum == target) return 1;
            else return 0;
        }
        if(mp.find(idx)!=mp.end() && mp[idx].find(sum)!=mp[idx].end() ) return mp[idx][sum];
        return mp[idx][sum] = solve(nums,target,idx+1,sum+(nums[idx])) + solve(nums,target,idx+1,sum+(nums[idx]*-1));
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }
};