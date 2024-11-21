class Solution {
public:
    set<vector<int>> st;
    void dfs(int row,int col,vector<vector<int>> &vis,int r,int c,int &m,int &n) {
        int newrow = row+r;
        int newcol = col+c;
        while(newrow >=0 && newrow < m && newcol >= 0 && newcol < n && vis[newrow][newcol] != -1 && st.count({newrow,newcol,r,c}) == 0) {
            st.insert({newrow,newcol,r,c});
            vis[newrow][newcol] = 1;
            newrow += r;
            newcol += c;
        }
        return;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(auto i: walls) {
            vis[i[0]][i[1]] = -1;
        }
        for(auto i: guards) {
            dfs(i[0],i[1],vis,-1,0,m,n);
            dfs(i[0],i[1],vis,1,0,m,n);
            dfs(i[0],i[1],vis,0,-1,m,n);
            dfs(i[0],i[1],vis,0,1,m,n);
            vis[i[0]][i[1]] = -1;
        }
        int cnt = 0;
        for(int i =0; i<m; i++) {
            for(int j =0; j<n; j++) {
                if(vis[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};