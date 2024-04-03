class Solution {
public:
    bool f(vector<vector<char>> &board) {
        // int n = board.size();
        // int m = board[0].size();
        for(int i =0; i<9; i++) {
            for(int j =0; j<9; j++) {
                if(board[i][j] == '.') {
                    for(char ind = '1'; ind<='9'; ind++) {
                        if(help(board,i,j,ind)) {
                            board[i][j] = ind;
                            if(f(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool help(vector<vector<char>> &board,int i,int j,char c) {
        for(int ind=0; ind<9; ind++) {
            if(board[i][ind] == c) return false;
            if(board[ind][j] == c) return false;
            if(board[3*(i/3)+(ind/3)][3*(j/3)+(ind%3)] == c) return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
        return;
    }
};