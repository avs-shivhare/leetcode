class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> temp;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                temp.push_back({grid[i][j],i,j});
            }
        }
        sort(temp.begin(),temp.end());
        vector<int> t(k+1,0);
        vector<vector<vector<int>>> dist(n,vector<vector<int>>(m,vector<int>(k+1,INT_MAX)));
        priority_queue<pair<int,pair<int,pair<int,int>>>,vector<pair<int,pair<int,pair<int,int>>>>,greater<pair<int,pair<int,pair<int,int>>>>> q;
        int rowdiff[2] = {1,0};
        int coldiff[2] = {0,1};
        dist[0][0][0] = 0;
        q.push({0,{0,{0,0}}});
        while(!q.empty()) {
            int cost = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second.first;
            int x = q.top().second.second.second;
            q.pop();
            if(r == n-1 && c == m-1) return cost;
            if(cost > dist[r][c][x] || dist[n-1][m-1][x] < cost) continue;
            for(int i = 0; i<2; i++) {
                int nr = r+rowdiff[i];
                int nc = c+coldiff[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc][x] > cost+grid[nr][nc]) {
                    dist[nr][nc][x] = cost+grid[nr][nc];
                    q.push({dist[nr][nc][x],{nr,{nc,x}}});
                }
            }
            if(x+1 <= k) {
                int p = t[x];
                while(p < temp.size()) {
                    if(temp[p][0] > grid[r][c]) break;
                    int nr = temp[p][1];
                    int nc = temp[p][2];
                    if(dist[nr][nc][x+1] > cost) {
                        dist[nr][nc][x+1] = cost;
                        q.push({dist[nr][nc][x+1],{nr,{nc,x+1}}});
                    }
                    p++;
                }
                t[x] = p;
            }
        }
        int ans = INT_MAX;
        for(int x = 0; x<=k; x++) {
            ans = min(ans,dist[n-1][m-1][x]);
        }
        return ans;
    }
};