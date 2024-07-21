
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        unordered_map<int,int> zero_diff;
      
         vector<int>one_diff(k+1,0);
      
        int n = nums.size();

        // Calculate the frequency of each difference and store unique differences in a set
        for (int i = 0; i < n / 2; ++i) {
          
            zero_diff[abs(nums[i] - nums[n - 1 - i])]++;
            int maxElement = max(nums[i],nums[n-1-i]);
             int minElement = min(nums[i],nums[n-1-i]);
             int max_diff = max(
                abs(k-minElement),
                abs(0-maxElement)
             );
             one_diff[max_diff]+=1;
         
        }
        for(int i=k-1;i>=0;i--){
            one_diff[i] = one_diff[i] + one_diff[i+1];
        }
        
        int cnt = INT_MAX;
        int possible_pair = n/2;
        for(auto [key,value]:zero_diff){
            int one_operation = abs(one_diff[key] - value);
            int two_operation = abs(possible_pair - one_operation - value )*2;
            cnt = min(cnt,one_operation+two_operation);
            
        }

        return cnt;

    
    }
};
