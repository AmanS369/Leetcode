class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
      int m = rolls.size();
        int totalSum = mean * (n + m);  
        int currentSum = accumulate(rolls.begin(), rolls.end(), 0);  
        
        int totalRem = totalSum - currentSum;  
        if (totalRem < n || totalRem > 6 * n) {
            return {};
        }
        
        
        vector<int> result(n, 1);  
        totalRem -= n; 
        
       
        for (int i = 0; i < n && totalRem > 0; ++i) {
            int add = min(5, totalRem); 
            result[i] += add;
            totalRem -= add;
        }
        
        return result;
    }
};