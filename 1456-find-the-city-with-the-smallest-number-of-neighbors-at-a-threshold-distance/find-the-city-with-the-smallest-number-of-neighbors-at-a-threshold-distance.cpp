class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thres) {
          vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

         for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

int city=0;
int cityMax=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
            if(dist[i][j]<=thres){
                cnt++;
            }

            }
            if(cnt < cityMax){
                cityMax = cnt;
                city = i;
            }else if(cnt == cityMax){
                 city = max(city,i);
            }
        }
        return city;

    }
};