class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        int rowdiff[4] = {1,-1,0,0};
        int coldiff[4] = {0,0,1,-1};
        vector<vector<int>> dist(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>> q;
        dist[0][0] = health-grid[0][0];
        q.push({dist[0][0],{0,0}});
        while(!q.empty()) {
            int cost = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            if(dist[r][c] > cost) continue;
            for(int i = 0; i<4; i++) {
                int nr = r+rowdiff[i];
                int nc = c+coldiff[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] < cost-grid[nr][nc]) {
                    dist[nr][nc] = cost-grid[nr][nc];
                    q.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        return dist[n-1][m-1] >= 1;
    }
};