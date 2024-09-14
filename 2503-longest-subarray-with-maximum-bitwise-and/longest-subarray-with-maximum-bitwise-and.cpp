class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = -1;
        for(auto i:nums) maxi = max(i,maxi);
        int cnt =0;
        int ans=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == maxi) cnt++;
            else cnt =0;
            ans = max(ans,cnt);
        }
        return ans;
    }
};