class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int maxFreq = 0, left = 0, ans = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            maxFreq = max(maxFreq, freq[nums[right]]);
            ans = max(ans, maxFreq);
            
            while ((right - left + 1) - maxFreq > k) {
                freq[nums[left]]--;
                maxFreq = max(maxFreq, freq[nums[left]]);
                left++;
            }

            
        }
        
        return ans;
    }
};
