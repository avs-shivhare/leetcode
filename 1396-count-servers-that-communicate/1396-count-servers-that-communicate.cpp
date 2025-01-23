class Solution {
public:
    int dfs(int r,int c,vector<vector<bool>> &vis,vector<pair<int,int>> adj[],vector<pair<int,int>> adj2[]) {
        vis[r][c] = true;
        int ans = 1;
        for(auto i: adj[r]) {
            if(!vis[i.first][i.second]) {
                ans += dfs(i.first,i.second,vis,adj,adj2);
            }
        }
        for(auto i: adj2[c]) {
            if(!vis[i.first][i.second]) {
                ans += dfs(i.first,i.second,vis,adj,adj2);
            }
        }
        return ans;
    }
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> adj[n];
        vector<pair<int,int>> adj2[m];
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j]) {
                    adj[i].push_back({i,j});
                    adj2[j].push_back({i,j});
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    int temp = dfs(i,j,vis,adj,adj2);
                    if(temp != 1) ans += temp;
                }
            }
        }
        return ans;
    }
};