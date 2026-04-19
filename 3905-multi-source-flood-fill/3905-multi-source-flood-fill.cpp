class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& s) {
        vector<vector<int>> dist(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,INT_MAX));
        queue<vector<int>> q;
        for(auto &i: s) {
            q.push({i[0],i[1],0,i[2]});
            vis[i[0]][i[1]] = 0;
            dist[i[0]][i[1]] = i[2];
        }
        int rowdiff[4] = {0,0,1,-1};
        int coldiff[4] = {1,-1,0,0};
        while(!q.empty()) {
            int si = q.size();
            while(si--) {
                int r = q.front()[0];
                int c = q.front()[1];
                int t = q.front()[2];
                int coll = q.front()[3];
                q.pop();
                if(dist[r][c] != coll) continue;
                // cout<<r<<" "<<c<<" "<<t<<" "<<coll<<endl;
                for(int i = 0; i<4; i++) {
                    int nr = r+rowdiff[i];
                    int nc = c+coldiff[i];
                    // if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    //     cout<<dist[nr][nc]<<" "<<coll<<endl;
                    // }
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] >= t+1 && dist[nr][nc] < coll) {
                        dist[nr][nc] = coll;
                        q.push({nr,nc,t+1,coll});
                        vis[nr][nc] = t+1;
                    }
                }
            }
        }
        return dist;
    }
};