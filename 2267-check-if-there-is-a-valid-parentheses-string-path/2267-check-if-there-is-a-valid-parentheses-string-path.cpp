class Solution {
public:
    int dp[101][101][999];
    int find(int r,int c,int cnt,vector<vector<char>> &grid) {
        //cout<<r<<" "<<c<<" "<<cnt<<endl;
        if(cnt < 0 || r >= grid.size() || c >= grid[0].size()) return 0;
        if(r == grid.size()-1 && grid[0].size()-1 == c) {
            if(grid[r][c] == '(') cnt++;
            else cnt--;
            if(cnt == 0) return 1;
            return 0;
        }
        if(dp[r][c][cnt] != -1) return dp[r][c][cnt];
        int ans = 0;
        if(grid[r][c] == '(') ans = max(find(r+1,c,cnt+1,grid),find(r,c+1,cnt+1,grid));
        else ans = max(find(r+1,c,cnt-1,grid),find(r,c+1,cnt-1,grid));
        return dp[r][c][cnt] = ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans = find(0,0,0,grid);
        cout<<ans<<endl;
        return ans;
    }
};