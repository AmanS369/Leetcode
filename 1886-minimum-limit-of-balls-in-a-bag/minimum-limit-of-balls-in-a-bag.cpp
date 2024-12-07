class Solution {
public:
 bool isPossible(vector<int>& nums, int mid, int maxOperations) {
        int operation = 0;
        for (int n : nums) {
            operation += (n + mid - 1) / mid - 1;
            if (operation > maxOperations) return false;
        }
        return true;
        
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int res = right;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, mid, maxOperations)) {
                right = mid;
                res = right;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
};