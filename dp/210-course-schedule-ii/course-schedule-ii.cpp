class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        map<int,vector<int>>adj;
        
        vector<int>indegree(n,0);
        for(auto i :prerequisites ){
            int v = i[0];
            int u = i[1];
            adj[u].push_back(v);
            indegree[v]+=1;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int>ans;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto neigh:adj[top]){
                indegree[neigh]--;
                if(indegree[neigh]==0)q.push(neigh);
            }
        }

        if(ans.size()!=n) return {};

        return ans;

    }
};