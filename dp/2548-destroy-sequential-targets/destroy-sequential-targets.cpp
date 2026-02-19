class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> freq;
        
        for(int x : nums){
            freq[x % space]++;
        }
        
        int maxFreq = 0;
        int ans = INT_MAX;
        
        for(int x : nums){
            int r = x % space;
            
            if(freq[r] > maxFreq){
                maxFreq = freq[r];
                ans = x;
            }
            else if(freq[r] == maxFreq){
                ans = min(ans, x);
            }
        }
        
        return ans;
    }
};
