class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        dist[0][0] = 0;
        int row[4] = {1,-1,0,0};
        int col[4] = {0,0,-1,1};
        while(!q.empty()) {
            int cost = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            for(int i =0; i<4; i++) {
                int newrow = r+row[i];
                int newcol = c+col[i];
                if(newrow >=0 && newrow < n && newcol >= 0 && newcol < m) {
                    if(grid[newrow][newcol]) {
                        if(dist[newrow][newcol] > cost+1) {
                            dist[newrow][newcol] = cost+1;
                            q.push({cost+1,{newrow,newcol}});
                        }
                    }
                    else {
                        if(dist[newrow][newcol] > cost) {
                            dist[newrow][newcol] = cost;
                            q.push({cost,{newrow,newcol}});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};