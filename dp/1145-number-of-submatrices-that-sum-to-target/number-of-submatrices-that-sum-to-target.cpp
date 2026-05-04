class Solution {
public:
    int solve(vector<int>nums,int k){
        map<int,int> mp;
        mp[0]=1;
        int presum=0,count=0;
        //prefix sumi
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int search= presum - k;
            count+=mp[search];
            mp[presum]+=1;

        }

        return count;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<int>dp(c,0);
        int ans=0;

        for (int top = 0; top < r; top++) {
            vector<int> dp(c, 0);  // reset for each top

            // Fix bottom row
            for (int bottom = top; bottom < r; bottom++) {

                // build column sums
                for (int j = 0; j < c; j++) {
                    dp[j] += matrix[bottom][j];
                }

                // count subarrays
                ans += solve(dp, target);
            }
        }
        return ans;

        

        
    }
};