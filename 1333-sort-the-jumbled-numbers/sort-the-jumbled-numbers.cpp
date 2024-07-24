class Solution {
public:
static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>vec(nums.size());
        vector<int>ans(nums.size());
      for (int i = 0; i < nums.size(); i++) {
        int newDigit = 0;
        string oldDigitStr = to_string(nums[i]);
        
        for (char c : oldDigitStr) {
            int digit = c - '0'; 
            newDigit = newDigit * 10 + mapping[digit];
        }

        cout << newDigit << endl;
        vec[i] = {newDigit, nums[i]};
    }
        sort(vec.begin(),vec.end(),cmp);
      //  for(auto i:vec) cout<<i.first<<" ";
        for(int i=0;i<nums.size();i++){
            ans[i] = vec[i].second;
        }
        return ans;
    }
};