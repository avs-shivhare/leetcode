class Solution {
public:
    int rowdiff[4] = {-1,0,0,1};
    int coldiff[4] = {0,-1,1,0};
    void bfs(vector<vector<int>> &safe,vector<vector<int>> &grid,int &n) {
        queue<pair<int,int>> q;
        for(int i =0; i<n; i++) {
            for(int j =0; j<n; j++) {
                if(grid[i][j]) {
                    safe[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i =0; i<4; i++) {
                int newRow = row+rowdiff[i];
                int newCol = col+coldiff[i];
                if(newRow >= 0 && newRow <n && newCol >= 0 && newCol < n && safe[newRow][newCol] > safe[row][col]+1) {
                    safe[newRow][newCol] = safe[row][col]+1;
                    q.push({newRow,newCol});
                } 
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safe(n,vector<int>(n,1e9));
        bfs(safe,grid,n);
        priority_queue<pair<int,pair<int,int>>> q;
        q.push({safe[0][0],{0,0}});
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vis[0][0] = true;
        while(!q.empty()) {
            int cost = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            if(row == n-1 && col== n-1) return cost;
            for(int i =0; i<4; i++) {
                int newRow = row+rowdiff[i];
                int newCol = col+coldiff[i];
                if(newRow >=0 && newRow <n && newCol >=0 && newCol < n && !vis[newRow][newCol]) {
                    q.push({min(cost,safe[newRow][newCol]),{newRow,newCol}});
                    vis[newRow][newCol] = true;
                }
            }
        }
        return 0;
    }
};