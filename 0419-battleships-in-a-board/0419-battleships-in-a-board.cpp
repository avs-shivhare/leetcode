class Solution {
public:
    int rowdiff[4] = {-1,0,0,1};
    int coldiff[4] = {0,-1,1,0};
    void dfs(int row,int col,vector<vector<char>> &board,vector<vector<bool>> &vis,int &n,int &m) {
        vis[row][col] = true;
        for(int i =0; i<4; i++) {
            int newRow = row+rowdiff[i];
            int newCol = col+coldiff[i];
            if(newRow>=0 && newRow<n && newCol >= 0 && newCol<m && board[newRow][newCol] == 'X' && !vis[newRow][newCol]) {
                dfs(newRow,newCol,board,vis,n,m);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i =0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(!vis[i][j] && board[i][j] == 'X') {
                    cnt++;
                    dfs(i,j,board,vis,n,m);
                }
            }
        }
        return cnt;
    }
};