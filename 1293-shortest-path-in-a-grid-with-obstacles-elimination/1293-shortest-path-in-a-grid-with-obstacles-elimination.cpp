class Solution {
public:
    int rowdiff[4] = {-1,0,0,1};
    int coldiff[4] = {0,-1,1,0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(m,vector<bool>(k+1,false)));
        queue<pair<pair<int,int>,pair<int,int>>> q;
        q.push({{0,0},{k,0}});
        vis[0][0][k] = true;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int rem = q.front().second.first;
            int step = q.front().second.second;
            q.pop();
            if(row == n-1 && col == m-1) return step;
            for(int i =0; i<4; i++) {
                int newRow = row+rowdiff[i];
                int newCol = col+coldiff[i];
                if(newRow >=0 && newRow < n && newCol >=0 && newCol < m ) {
                    if(grid[newRow][newCol] == 0 && !vis[newRow][newCol][rem]) {
                        vis[newRow][newCol][rem] = true;
                        q.push({{newRow,newCol},{rem,step+1}});
                    }
                    else if(grid[newRow][newCol] == 1 && rem > 0 && !vis[newRow][newCol][rem-1]) {
                        vis[newRow][newCol][rem-1] = true;
                        q.push({{newRow,newCol},{rem-1,step+1}});
                    }
                }
            }
        }
        return -1;
    }
};