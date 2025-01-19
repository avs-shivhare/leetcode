class Solution {
public:
    int rowdiff[4] = {0,0,-1,1};
    int coldiff[4] = {1,-1,0,0};
    int trapRainWater(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    q.push({nums[i][j],{i,j}});
                    vis[i][j] = true;
                }
            }
        }
        int ans = 0;
        while(!q.empty()) {
            auto cost = q.top().first;
            auto r = q.top().second.first;
            auto c = q.top().second.second;
            q.pop();
            for(int i = 0; i<4; i++) {
                int newrow = r+rowdiff[i];
                int newcol = c+coldiff[i];
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !vis[newrow][newcol]) {
                    if(cost-nums[newrow][newcol] > 0) ans += cost-nums[newrow][newcol];
                    q.push({max(cost,nums[newrow][newcol]),{newrow,newcol}});
                    vis[newrow][newcol] = true;
                }
            }
        }
        return ans;
    }
};