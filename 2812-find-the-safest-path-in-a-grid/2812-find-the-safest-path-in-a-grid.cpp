class Solution {
public:
    int distance(int a,int b,int c,int d) {
        return abs(a-c)+abs(b-d);
    }
    int find(int r,int c,vector<vector<int>> &dp) {
        if(r >= dp.size() || c >= dp[0].size()) return 0;
        return dp[r][c];
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int rowdiff[4] = {1,-1,0,0};
        int coldiff[4] = {0,0,1,-1};
        vector<pair<int,int>> temp;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j]) temp.push_back({i,j});
            }
        }
        vector<vector<int>> dp(n,vector<int>(m,0));
        vector<vector<int>> safe(n,vector<int>(m,INT_MAX));
        queue<pair<int,pair<int,int>>> q2;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j]) {
                    safe[i][j] = 0;
                    q2.push({0,{i,j}});
                }
            }
        }
        while(!q2.empty()) {
            int cost = q2.front().first;
            int r = q2.front().second.first;
            int c = q2.front().second.second;
            q2.pop();
            for(int i = 0; i<4; i++) {
                int nr = r+rowdiff[i];
                int nc = c+coldiff[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && safe[nr][nc] > cost+1) {
                    safe[nr][nc] = cost+1;
                    q2.push({cost+1,{nr,nc}});
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>> q;
        q.push({safe[0][0],{0,0}});
        dp[0][0] = safe[0][0];
        while(!q.empty()) {
            int cost = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            if(dp[r][c] > cost) continue;
            for(int i = 0; i<4; i++) {
                int nr = r+rowdiff[i];
                int nc = c+coldiff[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && dp[nr][nc] < min(cost,safe[nr][nc])) {
                    dp[nr][nc] = min(cost,safe[nr][nc]);
                    q.push({dp[nr][nc],{nr,nc}});
                }
            }
        }
        return dp[n-1][m-1];
    }
};