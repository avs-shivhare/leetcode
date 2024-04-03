class Solution {
public:
    int rowdiff[4] = {-1,0,0,1};
    int coldiff[4] = {0,-1,1,0};
    bool f(int row,int col,int ind,int &n,int &m,vector<vector<char>> &board,string &word,vector<vector<bool>> &vis,int &s) {
        if(ind == s) return true;
        vis[row][col] = true;
        for(int i=0; i<4; i++) {
            int newRow = row+rowdiff[i];
            int newCol = col+coldiff[i];
            if(newRow>=0 && newRow<n && newCol >=0 && newCol<m && !vis[newRow][newCol] && word[ind] == board[newRow][newCol]) {
                if(f(newRow,newCol,ind+1,n,m,board,word,vis,s)) return true;
            }
        }
        vis[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int s = word.size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i =0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(board[i][j] == word[0]) {
                    if(f(i,j,1,n,m,board,word,vis,s)) return true;
                }
            }
        }
        return false;
    }
};