class Solution {
public:
    void f(int col,int &n,vector<string> &board,long long &ans,vector<bool> &left,vector<bool> &upper,vector<bool> &lower) {
        if(col== n) {
            ans++;
            return;
        }
        for(int row =0; row<n; row++) {
            if(!left[row] && !upper[row+col] && !lower[n-1+col-row]) {
                left[row] = true;
                upper[row+col] = true;
                lower[n-1+col-row] = true;
                board[row][col] = 'Q';
                f(col+1,n,board,ans,left,upper,lower);
                left[row] = false;
                upper[row+col] = false;
                lower[n-1+col-row] = false;
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        string s(n,'.');
        vector<string> board(n,s);
        vector<bool> left(n,false),upper(n,false),lower(n,false);
        long long ans =0;
        f(0,n,board,ans,left,upper,lower);
        return ans;
    }
};