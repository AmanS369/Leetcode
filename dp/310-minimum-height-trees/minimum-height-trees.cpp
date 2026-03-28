class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      vector<int>indegree(n,0),ans;
       unordered_map<int,vector<int>>adj;
         for(auto i:edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
              q.push(i);
             indegree[i]--;
            } 
        }

        while(!q.empty()){
            int s = q.size();
            ans.clear();
            while(s--){
                int front = q.front();
             q.pop();
             ans.push_back(front);
              for(auto neigh :adj[front]){
                indegree[neigh]--;
                if(indegree[neigh]==1) q.push(neigh);
             }
            }
        }
        if(n==1) ans.push_back(0);
        return ans;
    }
};