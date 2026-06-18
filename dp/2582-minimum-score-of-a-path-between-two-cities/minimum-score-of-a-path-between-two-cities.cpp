class Solution {
public:
 vector<int> parent;
        int findParent(int x) {
        if (parent[x] == x) return x;
          return parent[x] = findParent(parent[x]);
        }

        void unite(int u, int v) {
           int pu = findParent(u);
           int pv = findParent(v);

          if (pu != pv)parent[pu] = pv;
        }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &r : roads)
            unite(r[0], r[1]);

        int root = findParent(1);
        int ans = INT_MAX;

        for (auto &r : roads) {
            if (findParent(r[0]) == root)
                ans = min(ans, r[2]);
        }

        return ans;

    }
};