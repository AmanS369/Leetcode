class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        const int OFFSET = 10001;

        DSU dsu(20002);

        unordered_set<int> nodes;

        for (auto &stone : stones) {
            int row = stone[0];
            int col = stone[1] + OFFSET;

            dsu.unite(row, col);

            nodes.insert(row);
            nodes.insert(col);
        }

        int components = 0;

        for (int node : nodes) {
            if (dsu.find(node) == node)
                components++;
        }

        return stones.size() - components;
    }
};