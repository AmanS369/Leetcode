class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
    
        if(nums.size() <= 1) return nums.size(); 
        int ans =1;
        int n = nums.size();
        int i=0;
        int j=1;
        while(i<n && j<n){
            if( nums[i] < nums[j] ){
                int temp=1;
                while(i<n && j<n  && nums[i] < nums[j] ){
                     temp++;
                     i++;
                     j++;
                }
                ans = max(ans,temp);
                
            }else if( nums[i] > nums[j]){
                int temp=1;
                while(i<n && j<n && nums[i] > nums[j] ){
                     temp++;
                     i++;
                     j++;
                }
                ans = max(ans,temp);
            }
            else{
                     i++;
                     j++;
            }
        }
        return ans;
    }
};