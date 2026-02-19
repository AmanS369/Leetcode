class Solution {
public:
    unordered_map<int, vector<int>> adj;

    void dfs(int node, vector<bool>& visited, long long& size) {
        visited[node] = true;
        size++;

        for (auto neigh : adj[node]) {
            if (!visited[neigh]) {
                dfs(neigh, visited, size);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        vector<long long> componentSizes;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long size = 0;
                dfs(i, visited, size);
                componentSizes.push_back(size);
            }
        }

        long long totalPairs = 0;
        long long sumSoFar = 0;

        for (auto size : componentSizes) {
            totalPairs += size * sumSoFar;
            sumSoFar += size;
        }

        return totalPairs;
    }
};
