class Solution {
public:
    int trapRainWater(vector<vector<int>>& arr) {
        int rowdiff[4] = {0,0,1,-1};
        int coldiff[4] = {1,-1,0,0};
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dist = arr;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if((i == 0 || j == 0 || j == m-1 || i == n-1) && !vis[i][j]) {
                    //cout<<i<<" "<<j<<endl;
                    q.push({arr[i][j],i,j});
                    vis[i][j] = true;
                    //dist[i][j] = arr[i][j];
                }
            }
        }
        while(!q.empty()) {
            int val = q.top()[0];
            int r = q.top()[1];
            int c = q.top()[2];
            //cout<<r<<" "<<c<<" -> "<<val<<endl;
            q.pop();
            for(int i = 0; i<4; i++) {
                int nr = r+rowdiff[i];
                int nc = c+coldiff[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                    //cout<<nr<<" "<<nc<<" "<<val<<endl;
                    dist[nr][nc] = max(dist[nr][nc],val);
                    vis[nr][nc] = true;
                    q.push({dist[nr][nc],nr,nc});
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                //cout<<dist[i][j]<<" ";
                ans += dist[i][j]-arr[i][j];
            }
            //cout<<endl;
        }
        // for(int i = 0; i<n; i++) {
        //     for(int j = 0; j<m; j++) {
        //         cout<<vis[i][j]<<" ";
        //         ans += dist[i][j]-arr[i][j];
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};