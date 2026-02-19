class Solution {
public:
    unordered_map<int,vector<int>>adj;

    unordered_map<int,int>parent;

    void dfsParent(int node, int par) {
        parent[node] = par;
        for (int neigh : adj[node]) {
            if (neigh == par) continue;
            dfsParent(neigh, node);
        }
    }

    int dfs(int node ,unordered_map<int,int>&timeSheet, int par,vector<int>& amount,int time){
        int ans=0;
        if(timeSheet.count(node)){
           if(timeSheet[node]==time){
            //if on same time bob was there 
            ans=(amount[node]/2);
          }else if(timeSheet[node] < time){
            //bob already visited before alice
            ans = 0;
          }else{
           ans = amount[node];
          }
        } else {
            ans = amount[node];
        }
       
        int maxi=INT_MIN;
        for(auto neigh:adj[node]){
             
              if (neigh == par) continue;
               maxi = max(maxi,dfs(neigh,timeSheet,node,amount,time+1)); 
             
        }
        maxi = maxi==INT_MIN?0:maxi;
        return ans + maxi;

    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        for(auto i: edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfsParent(0, -1);
        unordered_map<int,int>bobTime;
        // Step 2: Compute Bob's time on path to root
        int t = 0;
        while (bob != -1) {
            bobTime[bob] = t;
            bob = parent[bob];
            t++;
        }

        return dfs(0,bobTime,-1,amount,0);
    }
};