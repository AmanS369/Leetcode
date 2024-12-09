class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
         int m = queries.size();
        vector<int>prefix(n-1,0);
        vector<int>prefix2(n,0);
        vector<bool>ans(m);
    
        for(int i=0;i<n-1;++i){
              
         if(nums[i]%2!=nums[i+1]%2) prefix[i]=1;
            
        }
       
for (int i = 1; i < n; ++i) {
    if (i - 1 < n - 1) {
        prefix2[i] = prefix2[i - 1] + prefix[i - 1];
    } else {
        prefix2[i] = prefix2[i - 1];
    }
}

       
        
        for(int i=0;i<m;i++){
            int st = queries[i][0];
            int ed = queries[i][1];
            bool res = (prefix2[ed] - prefix2[st] == (ed - st));
            ans[i] = res;
        }
        return ans;
    }
};