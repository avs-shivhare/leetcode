class Solution {
public:
    int rowdiff[4] = {-1,0,0,1};
    int coldiff[4] = {0,-1,1,0};
    void dfs(int row,int col,vector<vector<int>> &land,vector<vector<bool>> &vis,pair<int,int> &lower,int &n,int &m) {
        vis[row][col] = true;
        for(int i =0; i<4; i++) {
            int newRow = row+rowdiff[i];
            int newCol = col+coldiff[i];
            if(newRow >=0 && newRow < n && newCol >=0 && newCol < m && land[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                if(rowdiff[i] == 1 || coldiff[i] == 1) {
                    lower.first = newRow;
                    lower.second = newCol;
                }
                dfs(newRow,newCol,land,vis,lower,n,m);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> ans;
        pair<int,int> lower;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i =0; i<n; i++) {
            for(int j =0; j<m;j++) {
                if(land[i][j] && !vis[i][j]) {
                    lower.first = i;
                    lower.second = j;
                    dfs(i,j,land,vis,lower,n,m);
                    ans.push_back({i,j,lower.first,lower.second});
                }
            }
        }
        return ans;
    }
};