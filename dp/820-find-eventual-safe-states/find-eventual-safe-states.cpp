class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] == 1) return false; // cycle
        if (state[node] == 2) return true;  // already safe

        state[node] = 1; // mark visiting

        for (int neigh : graph[node]) {
            if (!dfs(neigh, graph, state)) {
                return false; // if any neighbor unsafe → unsafe
            }
        }

        state[node] = 2; // mark safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
