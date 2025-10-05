class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        queue<pair<int,int>> q;
        int rowdiff[4] = {0,0,1,-1};
        int coldiff[4] = {1,-1,0,0};
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> vis(n,vector<bool>(m,false)),vis2(n,vector<bool>(m,false));
        for(int i = 0; i<m; i++) {
            vis[0][i] = true;
            q.push({0,i});
        }
        for(int i = 1; i<n; i++) {
            vis[i][0] = true;
            q.push({i,0});
        }
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++) {
                int nr = r+rowdiff[i];
                int nc = c+coldiff[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && arr[r][c] <= arr[nr][nc]) {
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
        for(int i = 0; i<n; i++) {
            vis2[i][m-1] = true;
            q.push({i,m-1});
        }
        for(int i = 0; i<m-1; i++) {
            vis2[n-1][i] = true;
            q.push({n-1,i});
            //cout<<n-1<<" "
        }
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++) {
                int nr = r+rowdiff[i];
                int nc = c+coldiff[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis2[nr][nc] && arr[r][c] <= arr[nr][nc]) {
                    vis2[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                //cout<<vis2[i][j]<<" ";
                if(vis[i][j] && vis2[i][j]) ans.push_back({i,j});
            }
            //cout<<endl;
        }
        return ans;
    }
};