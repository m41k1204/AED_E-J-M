class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<unordered_map<char, bool>>(9);
        cols = vector<unordered_map<char, bool>>(9);
        boxes = vector<unordered_map<char, bool>>(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num != '.') {
                    rows[i][num] = true;
                    cols[j][num] = true;
                    int boxIndex = (i / 3) * 3 + j / 3;
                    boxes[boxIndex][num] = true;
                }
            }
        }

        solve(board, 0, 0);
    }

private:
    vector<unordered_map<char, bool>> rows;
    vector<unordered_map<char, bool>> cols;
    vector<unordered_map<char, bool>> boxes;

    bool solve(vector<vector<char>>& board, int row, int col) {
        if (row == 9) {
            return true;
        }

        if (col == 9) {
            return solve(board, row + 1, 0);
        }

        if (board[row][col] != '.') {
            return solve(board, row, col + 1);
        }

        for (char c = '1'; c <= '9'; ++c) {
            int boxIndex = (row / 3) * 3 + col / 3;

            if (rows[row].find(c) == rows[row].end() &&
                cols[col].find(c) == cols[col].end() &&
                boxes[boxIndex].find(c) == boxes[boxIndex].end()) {

                board[row][col] = c;
                rows[row][c] = true;
                cols[col][c] = true;
                boxes[boxIndex][c] = true;

                if (solve(board, row, col + 1)) {
                    return true;
                }

                board[row][col] = '.';
                rows[row].erase(c);
                cols[col].erase(c);
                boxes[boxIndex].erase(c);
            }
        }

        return false;
    }
};
