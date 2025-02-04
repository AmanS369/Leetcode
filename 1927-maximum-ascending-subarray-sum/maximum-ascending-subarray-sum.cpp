class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans =0;
        int prev = 0;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[prev] >= nums[i]){
                ans = max(ans,sum);
                sum=0;
            }
            prev = i;
            sum+=nums[i];
        }
        ans = max(ans,sum);
        return ans;
    }
};