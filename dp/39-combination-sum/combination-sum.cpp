class Solution {
public:
vector<vector<int>> ans;
    int n=0;
    void solve(int index , int currSum , int target,vector<int>output,vector<int>& c){
        if(index >= n || currSum > target) return;
        if(currSum == target){
            ans.push_back(output);
            return;
        }
        // taking
        if(c[index] + currSum <= target ){
          output.push_back(c[index]);
          solve(index,currSum+c[index],target,output,c);
          output.pop_back();
        }
       
        solve(index+1,currSum,target,output,c);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        n = c.size();
        vector<int>output;
        solve(0,0,target,output,c);
        return ans;
    }
};