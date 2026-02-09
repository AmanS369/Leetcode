class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto i:times){
         int u = i[0];
         int v  = i[1];
         int w = i[2];
         adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX);
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
         pq.push({0,k});
         dist[k] = 0;
         while(!pq.empty()){
            auto[dis,node] = pq.top();
            pq.pop();
            if(dist[node] < dis) continue;
            for(auto [v,w] : adj[node]){
                int newDis = w + dis;
                if(newDis < dist[v]){
                    dist[v] = newDis;
                    pq.push({newDis,v});
                }
            }
         }

         int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

         return ans;
    }
};