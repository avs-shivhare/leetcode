class Solution {
public:
    //using bfs but it get tle
    // int getMaximumGold(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vector<vector<bool>> vis(n,vector<bool>(m,false));
    //     priority_queue<pair<int,pair<int,pair<int,vector<vector<bool>>>>>> q;
    //     int rowdiff[4] = {-1,0,0,1};
    //     int coldiff[4] = {0,-1,1,0};
    //     for(int i =0; i<n; i++) {
    //         for(int j =0; j<m; j++) {
    //             if(grid[i][j] != 0) {
    //                 vis[i][j] = true;
    //                 q.push({grid[i][j],{i,{j,vis}}});
    //                 vis[i][j] = false;
    //             }
    //         }
    //     }
    //     int ans = 0;
    //     while(!q.empty()) {
    //         auto i = q.top();
    //         q.pop();
    //         auto sum = i.first;
    //         auto v = i.second.second.second;
    //         auto col = i.second.second.first;
    //         auto row = i.second.first;
    //         ans = max(ans,sum);
    //         for(int j = 0; j<4; j++) {
    //             int newRow = row+rowdiff[j];
    //             int newCol = col+coldiff[j];
    //             if(newRow >=0 && newRow <n && newCol >= 0 && newCol<m && !v[newRow][newCol] && grid[newRow][newCol] != 0) {
    //                 v[newRow][newCol] = true;
    //                 q.push({sum+grid[newRow][newCol],{newRow,{newCol,v}}});
    //                 v[newRow][newCol] = false;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    //solution with dfs
    int rowdiff[4] = {-1,0,0,1};
    int coldiff[4] = {0,-1,1,0};
    void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<bool>> &vis,int sum,int &maxi,int &n,int &m) {
        vis[row][col] = true;
        sum += grid[row][col];
        maxi = max(maxi,sum);
        for(int i =0; i<4; i++) {
            int newRow = row+rowdiff[i];
            int newCol = col+coldiff[i];
            if(newRow >=0 && newRow < n && newCol >=0 && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol]) {
                dfs(newRow,newCol,grid,vis,sum,maxi,n,m);
            }
        }
        vis[row][col] = false;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int ans = 0;
        for(int i =0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(grid[i][j] != 0) {
                    dfs(i,j,grid,vis,0,ans,n,m);
                }
            }
        }
        return ans;
    }
};