class Solution {
public:
    int rowdiff[4] = {0,0,1,-1};
    int coldiff[4] = {1,-1,0,0};
    int dfs(int r,int c,vector<vector<int>> &grid,vector<vector<bool>> &vis,int &n,int &m) {
        int ans =1;
        vis[r][c] = true;
        for(int i = 0; i<4; i++) {
            int newrow = r+rowdiff[i];
            int newcol = c+coldiff[i];
            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !vis[newrow][newcol] && grid[newrow][newcol]) {
                ans += dfs(newrow,newcol,grid,vis,n,m);
            } 
        }
        return ans;
    }
    void redfs(int r,int c,vector<vector<int>> &grid,int &n,int &m,int &temp,vector<vector<pair<int,int>>> &ans,int &cnt) {
        ans[r][c] = {temp,cnt};
        //cout<<r<<" "<<c<<" -> "<<temp<<" "<<cnt<<endl;
        for(int i = 0; i<4; i++) {
            int newrow = r+rowdiff[i];
            int newcol = c + coldiff[i];
            if(newrow >=0 && newrow < n && newcol >= 0 && newcol < m && ans[newrow][newcol].first == 0 && grid[newrow][newcol]) {
                redfs(newrow,newcol,grid,n,m,temp,ans,cnt);
            }
        }
        return;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<pair<int,int>>> ans(n,vector<pair<int,int>>(m,{0,0}));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    cnt++;
                    int temp = dfs(i,j,grid,vis,n,m);
                    redfs(i,j,grid,n,m,temp,ans,cnt);
                }
            }
        }
        int temp = 0;
        for(int i = 0; i<n; i++) {
            for(int j= 0; j<m; j++) {
                //cout<<ans[i][j].second<<" ";
                if(grid[i][j]) {
                    temp = max(temp,ans[i][j].first);
                    continue;
                }
                int x = 1;
                unordered_set<int> st;
                for(int p = 0; p<4; p++) {
                    int row = i+rowdiff[p];
                    int col = j+coldiff[p];
                    if(row >=0 && row < n && col >= 0 && col < m && !st.count(ans[row][col].second)) {
                        x += ans[row][col].first;
                        st.insert(ans[row][col].second);
                    }
                }
                temp = max(temp,x);
            }
            //cout<<endl;
        }
        return temp;
    }
};