class Solution {
public:
    int dfs(int node, unordered_map<int, vector<int>>& mp, vector<int>& informTime) {
        int maxTime = 0;

        for (auto child : mp[node]) {
            maxTime = max(maxTime, dfs(child, mp, informTime));
        }

        return informTime[node] + maxTime;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> mp;

        // build tree
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                mp[manager[i]].push_back(i);
            }
        }

        return dfs(headID, mp, informTime);
    }
};