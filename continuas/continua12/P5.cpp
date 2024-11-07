class Solution {
public:
    vector<vector<string>> res;
    int m;
    vector<string> addQ(vector<string> tb, int row, int col){
        for(int i = 0;i<m;i++){
            tb[row][i] = '.';
        }
        for(int i = row;i<m;i++){
            tb[i][col] = '.';
        }
        int x,y;
        x = row;
        y = col;
        while(x < m && y < m){
            tb[x][y] = '.';
            x++;
            y++;
        }
        x = row;
        y = col;
        while(x < m && y >= 0){
            tb[x][y] = '.';
            x++;
            y--;
        }
        tb[row][col] = 'Q';
        return tb;
    }
    void back(int row, vector<string> tb){
        if(row == m){
            res.push_back(tb);
            return;
        }
        for(int i = 0;i<m;i++){
            if(tb[row][i] == '.') continue;
            vector<string> t2 = addQ(tb,row,i);
            back(row+1,t2);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        m = n;
        vector<string> tb;
        string s;
        for(int i = 0;i<m;i++){
            s+=' ';
        }
        for(int i = 0;i<m;i++){
            tb.push_back(s);
        }
        back(0,tb);
        return res;
    }
};
