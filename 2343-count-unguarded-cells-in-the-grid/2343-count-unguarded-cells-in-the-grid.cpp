class Solution {
public:
    int rowdiff[4] = {0,0,1,-1};
    int coldiff[4] = {1,-1,0,0};
    set<vector<int>> st;
    void dfs(int r,int c,int dir,vector<vector<int>> &vis,int &n,int &m) {
        vis[r][c] = dir;
        int nr = r+rowdiff[dir];
        int nc = c+coldiff[dir];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] != dir && st.find({nr,nc}) == st.end()) {
            dfs(nr,nc,dir,vis,n,m);
        }
        return;
    }
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        for(auto i: walls) {
            st.insert(i);
        }
        vector<vector<int>> vis(n,vector<int>(m,-1));
        for(auto i: guards) {
            st.insert(i);
        }
        for(auto i: guards) {
            dfs(i[0],i[1],0,vis,n,m);
            dfs(i[0],i[1],1,vis,n,m);
            dfs(i[0],i[1],2,vis,n,m);
            dfs(i[0],i[1],3,vis,n,m);
        }
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(vis[i][j] == -1 && st.find({i,j}) == st.end()) cnt++;
            }
        }
        return cnt;
    }
};