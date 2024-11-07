class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> neighbor_vals(n); 
        int max_sum = vals[0]; 

        for (int i = 0; i < n; ++i) {
            if (vals[i] > max_sum)
                max_sum = vals[i];
        }

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (vals[v] > 0)
                neighbor_vals[u].push_back(vals[v]);
            if (vals[u] > 0)
                neighbor_vals[v].push_back(vals[u]);
        }

        for (int i = 0; i < n; ++i) {
            int sum = vals[i];
            auto& neighbors = neighbor_vals[i];
            if (!neighbors.empty()) {
                sort(neighbors.begin(), neighbors.end(), greater<int>());
                for (int j = 0; j < min(k, (int)neighbors.size()); ++j) {
                    sum += neighbors[j];
                }
            }
            if (sum > max_sum)
                max_sum = sum;
        }

        return max_sum;
    }
};
