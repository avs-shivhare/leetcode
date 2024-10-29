class Solution {
public:
    int rowdiff[3] = {-1,0,1};
    int coldiff[3] = {1,1,1};
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool vis[n][m];
        memset(vis,false,sizeof(vis));
        queue<pair<int,pair<int,int>>> q;
        for(int j = 0; j<n; j++) {
            q.push({0,{j,0}});
            vis[j][0] = true;
        }
        int ans = 0;
        while(!q.empty()) {
            int cost = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            ans = max(ans,cost);
            for(int i =0; i<3; i++) {
                int newrow = row+rowdiff[i];
                int newcol = col+coldiff[i];
                if(newrow >=0 && newrow<n && newcol >=0 && newcol < m && grid[row][col] < grid[newrow][newcol] && !vis[newrow][newcol]) {
                    q.push({cost+1,{newrow,newcol}});
                    vis[newrow][newcol] = true;
                }
            }
        }
        return ans;
    }
};