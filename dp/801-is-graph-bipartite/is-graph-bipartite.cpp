class Solution {
public:

   bool solve(unordered_map<int, list<int>>& adj, int node, vector<int>& nodeVal) {
       queue<int> q;
       nodeVal[node] = 0;
       q.push(node);

       while (!q.empty()) {
           int x = q.front();
           q.pop();

           int val = nodeVal[x] == 0 ? 1 : 0;

           for (auto neigh : adj[x]) {
               if (nodeVal[neigh] == -1) {
                   nodeVal[neigh] = val;
                   q.push(neigh);
               } 
               else if (nodeVal[neigh] != val) {
                   return false;
               }
           }
       }
       return true;
   }

   bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size();

       unordered_map<int, list<int>> adj;
       for (int i = 0; i < n; i++) {
           for (auto edge : graph[i]) {
               adj[i].push_back(edge);
               
           }
       }

       vector<int> nodeVal(n, -1);

       for (int i = 0; i < n; i++) {
           if (nodeVal[i] == -1) {
               if (!solve(adj, i, nodeVal))
                   return false;
           }
       }

       return true;
   }
};
