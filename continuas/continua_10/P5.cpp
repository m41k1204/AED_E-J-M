class DSU {
public:
    std::vector<int> parent;
    std::vector<int> rank;
    int components;

    DSU(int n) : parent(n + 1), rank(n + 1, 0), components(n) {
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return false; 
        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        components--; 
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges) {
        DSU dsuAlice(n);
        DSU dsuBob(n);

        int edgesRequired = 0;

        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                bool usedAlice = dsuAlice.unite(edge[1], edge[2]);
                bool usedBob = dsuBob.unite(edge[1], edge[2]);
                if (usedAlice || usedBob)
                    edgesRequired++;
            }
        }

        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (dsuAlice.unite(edge[1], edge[2]))
                    edgesRequired++;
            } else if (edge[0] == 2) {
                if (dsuBob.unite(edge[1], edge[2]))
                    edgesRequired++;
            }
        }

        if (dsuAlice.components != 1 || dsuBob.components != 1)
            return -1;

        return edges.size() - edgesRequired;
    }
};


