class Solution {
public:
    int find(vector<int> &arr,unordered_map<int,int> &mpp,int node) {
        int l = 0, r= arr.size()-1;
        int ans = 0;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(arr[mid] <= node) {
                ans = mpp[arr[mid]];
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    } 
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt = 0;
        vis[0][0] = true;
        q.push({grid[0][0],{0,0}});
        int rowdiff[4] = {1,-1,0,0};
        int coldiff[4] = {0,0,1,-1};
        unordered_map<int,int> mpp;
        int maxi = 0;
        while(!q.empty()) {
            int node = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            cnt++;
            maxi = max(maxi,node);
            mpp[maxi] = cnt;
            for(int i = 0; i<4; i++) {
                int newrow = r+rowdiff[i];
                int newcol = c+coldiff[i];
                if(newrow >=0 && newrow < n && newcol >=0 && newcol < m && !vis[newrow][newcol]) {
                    vis[newrow][newcol] = true;
                    q.push({grid[newrow][newcol],{newrow,newcol}});
                }
            }
        }
        vector<int> arr;
        for(auto i: mpp) {
            arr.push_back(i.first);
        }
        sort(arr.begin(),arr.end());
        vector<int> ans;
        for(auto i: queries) {
            if(i > maxi) ans.push_back(cnt);
            else {
                ans.push_back(find(arr,mpp,i-1));
            }
        }
        return ans;
    }
};