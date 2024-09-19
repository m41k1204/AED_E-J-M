class Solution {
public:
    bool eq (int li, int lj, int i, int j){
        if(li == i && lj == j) return false;
        if(lj == j) return true;
        if(li == i) return true;
        if(li/3 == i/3 && lj/3 == j/3) return true;
        return false;
    }
    bool check(vector<vector<char>>& board, int li, int lj){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(eq(li, lj, i, j)){
                    if(board[li][lj]==board[i][j]) return true;
                }
            }
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                if(check(board, i, j)) return false;
            }
        }
        return true;
    }
};
