class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum =0;
        int n = nums.size();
        vector<int>profit(n,0);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            profit[i] = (nums[i] ^ k) - nums[i];
        }
        sort(profit.begin(),profit.end());
        reverse(profit.begin(),profit.end());
        for(int i=1;i<n;i+=2){
            int pairSum = profit[i] + profit[i-1];
            if(pairSum > 0 )sum+=pairSum;
            else break;
        }
        return sum;
    }
};