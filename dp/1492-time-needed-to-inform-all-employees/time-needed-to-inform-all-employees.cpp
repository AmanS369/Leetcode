class Solution {
public:
    int solve(int node, vector<int>& it,unordered_map<int,vector<int>>&mp){
      int maxTime =0;
      for(auto sub: mp[node] ){
        maxTime=max(solve(sub,it,mp) , maxTime);
      }
      return maxTime + it[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>mp;
          for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                mp[manager[i]].push_back(i);
            }
        }
        return solve(headID,informTime,mp);
       
    }
};