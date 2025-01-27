class Solution {
public:
   
    void dfs(int node, vector<int> adj[], vector<bool>& reachable) {
        reachable[node] = true;
        for (auto it : adj[node]) {
            if (!reachable[it]) {
                dfs(it, adj, reachable);
            }
        }
    }

    vector<bool> checkIfPrerequisite(int N, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
      
        vector<int> adj[N];
        for (auto &p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }
        
       
        vector<vector<bool>> reachabilityMatrix(N, vector<bool>(N, false));
        for (int i = 0; i < N; i++) {
            dfs(i, adj, reachabilityMatrix[i]);
        }

        vector<bool> answer;
        for (auto &q : queries) {
            answer.push_back(reachabilityMatrix[q[0]][q[1]]);
        }
        
        return answer;
    }
};