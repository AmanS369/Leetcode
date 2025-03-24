class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        int i=0;
        int j =0;
        double maxAverage =INT_MIN;
        while(j<nums.size()){
            sum += nums[j];
            if(j-i+1==k){
              maxAverage = max(maxAverage,sum/k);
              sum = sum - nums[i];
              i++;
            }
            j++;
        }
        return maxAverage;
    }
};