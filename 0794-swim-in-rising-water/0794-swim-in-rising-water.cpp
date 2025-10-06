class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int rowdiff[4] = {0,0,1,-1};
        int coldiff[4] = {1,-1,0,0};
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        dist[0][0] = grid[0][0];
        q.push({grid[0][0],0,0});
        while(!q.empty()) {
            int maxi = q.top()[0];
            int r = q.top()[1];
            int c = q.top()[2];
            q.pop();
            for(int i = 0; i<4; i++) {
                int nr = r+rowdiff[i];
                int nc = c+coldiff[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && max(maxi,grid[nr][nc]) < dist[nr][nc]) {
                    dist[nr][nc] = max(maxi,grid[nr][nc]);
                    q.push({dist[nr][nc],nr,nc});
                }
            }
        }
        return dist[n-1][n-1];
    }
};