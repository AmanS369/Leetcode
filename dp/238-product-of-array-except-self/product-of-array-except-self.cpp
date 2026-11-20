class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1;
        int zeroC = 0;

        for (auto i : nums) {
            if (i == 0) zeroC++;
            else product *= i;
        }

        int n = nums.size();
        vector<int> ans(n, 0);

        if (zeroC > 1) return ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                if (zeroC > 0) ans[i] = 0;
                else ans[i] = product / nums[i];
            } 
            else {
                if (zeroC == 1) ans[i] = product;
            }
        }

        return ans;
    }
};