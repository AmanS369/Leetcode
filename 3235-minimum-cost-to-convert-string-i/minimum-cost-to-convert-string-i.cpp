class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> adj(26, vector<int>(26, INT_MAX));
        for(int i = 0; i < 26; i++) {
            adj[i][i] = 0;
        }

        int n = original.size();

        for (int i = 0; i < n; i++) {
            char u = original[i] - 'a';
            char v = changed[i] - 'a';
            adj[u ][v] = min( adj[u][v],cost[i]);
        }

        for(int src = 0; src < 26; src++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if(adj[i][src] < INT_MAX && adj[src][j] < INT_MAX) {
                        adj[i][j] = min(adj[i][j], adj[i][src] + adj[src][j]);
                    }
                }
            }
        }

        long long  cnt = 0;
        for(int i = 0; i < source.size(); i++) {
            if(source[i] != target[i]) {
                int cost = adj[source[i] - 'a'][target[i] - 'a'];
                if(cost != INT_MAX) {
                    cnt += cost;
                } else {
                    return -1;
                }
            }
        }
        return cnt;
    }
};
