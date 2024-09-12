#include <vector>

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> diff(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + grid[i-1][j-1];
            }
        }

        for (int i = stampHeight; i <= m; i++) {
            for (int j = stampWidth; j <= n; j++) {
                int sum = prefix[i][j] - prefix[i-stampHeight][j] - prefix[i][j-stampWidth] + prefix[i-stampHeight][j-stampWidth];
                if (sum == 0) {
                    diff[i-stampHeight][j-stampWidth]++;
                    diff[i-stampHeight][j]--;
                    diff[i][j-stampWidth]--;
                    diff[i][j]++;
                }
            }
        }

        vector<vector<int>> coverage(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                coverage[i][j] = (i > 0 ? coverage[i-1][j] : 0) +
                                 (j > 0 ? coverage[i][j-1] : 0) -
                                 (i > 0 && j > 0 ? coverage[i-1][j-1] : 0) +
                                 diff[i][j];

                if (grid[i][j] == 0 && coverage[i][j] == 0) return false;
            }
        }

        return true;
    }
};