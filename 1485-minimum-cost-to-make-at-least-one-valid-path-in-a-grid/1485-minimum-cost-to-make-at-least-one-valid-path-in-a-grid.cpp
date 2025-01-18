class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        dist[0][0] = 0;
        int rowdiff[4] = {0,0,1,-1};
        int coldiff[4] = {1,-1,0,0};
        while(!q.empty()) {
            int cost = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            for(int i = 0; i<4; i++) {
                int newrow = r+rowdiff[i];
                int newcol = c+coldiff[i];
                if(i+1 == grid[r][c]) {
                    if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m) {
                        if(dist[newrow][newcol] > cost) {
                            dist[newrow][newcol] = cost;
                            q.push({cost,{newrow,newcol}});
                        }
                    }
                }
                else {
                    if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m) {
                        if(dist[newrow][newcol] > cost+1) {
                            dist[newrow][newcol] = cost+1;
                            q.push({cost+1,{newrow,newcol}});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};