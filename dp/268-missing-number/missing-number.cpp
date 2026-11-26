class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int reqSum = (n*(n+1))/2;
        int sum =0;
        for(auto i : nums) sum+=i;
        if(sum == reqSum) return 0;
        return reqSum - sum;
    }
};