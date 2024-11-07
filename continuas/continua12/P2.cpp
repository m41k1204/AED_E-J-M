class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    unionSets(i, j);
                }
            }
        }

        std::unordered_set<int> provinces;
        for (int i = 0; i < n; ++i) {
            provinces.insert(findSet(i));
        }

        return provinces.size();
    }

private:
    std::vector<int> parent;

    int findSet(int x) {
        if (parent[x] != x) {
            parent[x] = findSet(parent[x]);    
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int px = findSet(x);
        int py = findSet(y);
        if (px != py) {
            parent[px] = py;
        }
    }
};

