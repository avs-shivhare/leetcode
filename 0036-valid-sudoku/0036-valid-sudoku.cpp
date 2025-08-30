class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r = 0; r<9; r++) {
            for(int c = 0; c<9; c++) {
                if(board[r][c] == '.') continue;
                for(int x = 0; x<9; x++) {
                    if(x != r && board[x][c] == board[r][c]) {
                        return false;
                    }
                    if(x != c && board[r][x] == board[r][c]) {
                        return false;
                    }
                    int nr = (r/3)*3+(x/3);
                    int nc = (c/3)*3+(x%3);
                    if(r != nr && c != nc && board[nr][nc] == board[r][c]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};