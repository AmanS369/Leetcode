class Solution {
public:
    int n = 0;
    
    void solve(vector<int>& nums, vector<int>& dp, vector<int>& arr, int& lastIndex) { 
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            arr[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) { 
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        arr[i] = j;
                    }
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size();  
        vector<int> dp(n, 1);
        vector<int> arr(n, 0);
        sort(nums.begin(), nums.end());  
        int lastIndex = 0;
        solve(nums, dp, arr, lastIndex);
        
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while (lastIndex != arr[lastIndex]) {
            lastIndex = arr[lastIndex];
            temp.push_back(nums[lastIndex]); 
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};
