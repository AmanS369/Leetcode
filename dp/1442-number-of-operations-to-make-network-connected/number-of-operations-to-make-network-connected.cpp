class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
            return -1;

        int ex = 0;
        DisjointSet ds(n);

        for (auto &con : connections) {
            int u = con[0];
            int v = con[1];

            if (ds.findUPar(u) != ds.findUPar(v)) {
                ds.unionBySize(u, v);
            } else {
                ex++;
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i)
                cnt++;
        }

        int required = cnt - 1;

        if (ex >= required)
            return required;

        return -1;
    }
};