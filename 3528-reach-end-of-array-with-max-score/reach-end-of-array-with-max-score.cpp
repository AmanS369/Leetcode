#define ll long long int
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        ll ans =0;
        ll prev = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i] >= nums[prev]){
                ans += (i-prev)*nums[prev];
                prev =i;
            }else if(i==n-1){
                ans += ((n-1)-prev)*nums[prev];
            }
        }
      
        return ans;
    }
};