class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int rowdiff[4] = {0,0,1,-1};
        int coldiff[4] = {1,-1,0,0};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(nums[i][j] == 1) {
                    q.push({0,{i,j}});
                    vis[i][j] = true;
                    nums[i][j] = 0;
                }
            }
        }
        while(!q.empty()) {
            auto cost = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            for(int i = 0; i<4; i++) {
                int newrow = r+rowdiff[i];
                int newcol = c+coldiff[i];
                if(newrow >=0 && newrow < n && newcol >=0 && newcol < m && !vis[newrow][newcol]) {
                    vis[newrow][newcol] = true;
                    nums[newrow][newcol]  = cost+1;
                    q.push({cost+1,{newrow,newcol}});
                }
            }
        }
        return nums;
    }
};