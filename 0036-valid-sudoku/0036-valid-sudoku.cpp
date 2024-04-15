class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i =0; i<n; i++) {
            for(int j =0; j<n; j++) {
                if(board[i][j] == '.') continue;
                int r1 =0;
                while(r1<n) {
                    if(board[r1][j] == board[i][j] && i != r1) return false;
                    if(board[i][r1] == board[i][j] && j != r1) return false;
                    int r = 3*(i/3)+(r1/3);
                    int c= 3*(j/3)+(r1%3);
                    if(board[r][c] == board[i][j] && r != i && c != j) return false;
                    r1++; 
                }
                
            }
        }
        return true;
    }
};