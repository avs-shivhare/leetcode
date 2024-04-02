class Solution {
public:
    //optimize code
    // void f(int col,int &n,vector<string> &board,vector<vector<string>> &ans,vector<bool> &left,vector<bool> &upper,vector<bool> &lower) {
    //     if(col == n) {
    //         ans.push_back(board);
    //         return;
    //     }
    //     for(int row =0;row<n; row++) {
    //         if(!left[row] && !upper[row+col] && !lower[n-1+col-row]) {
    //             left[row] = true;
    //             upper[row+col] = true;
    //             lower[n-1+col-row] = true;
    //             board[row][col] = 'Q';
    //             f(col+1,n,board,ans,left,upper,lower);
    //             left[row] = false;
    //             upper[row+col] = false;
    //             lower[n-1+col-row] = false;
    //             board[row][col] = '.';
    //         }
    //     }
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     string s(n,'.');
    //     vector<string> board(n,s);
    //     vector<bool> left(n,false);
    //     vector<bool> upper(2*n-1,false);
    //     vector<bool> lower(2*n-1,false);
    //     vector<vector<string>> ans;
    //     f(0,n,board,ans,left,upper,lower);
    //     return ans;
    // }

    //brute force code
    bool help(int row,int col,int &n,vector<string> &board) {
        int duprow = row;
        int dupcol = col;
        while(row>=0 && col>=0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(col>=0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void f(int col,int &n,vector<string> &board,vector<vector<string>> &ans) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row =0;row<n; row++) {
            if(help(row,col,n,board)) {
                board[row][col] = 'Q';
                f(col+1,n,board,ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> board(n,s);
        // vector<bool> left(n,false);
        // vector<bool> upper(2*n-1,false);
        // vector<bool> lower(2*n-1,false);
        vector<vector<string>> ans;
        // f(0,n,board,ans,left,upper,lower);
        f(0,n,board,ans);
        return ans;
    }
};