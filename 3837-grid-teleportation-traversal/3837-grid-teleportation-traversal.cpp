class Solution {
public:
    int minMoves(vector<string>& matrix) {
        vector<pair<int,int>> adj[26];
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if('A' <= matrix[i][j] && matrix[i][j] <= 'Z') {
                    adj[matrix[i][j]-'A'].push_back({i,j});
                }
            }
        }
        vector<vector<int>> vis(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        vis[0][0] = 0;
        vector<bool> visit(26,false);
        q.push({0,{0,0}});
        int rowdiff[4] = {1,-1,0,0};
        int coldiff[4] = {0,0,1,-1};
        while(!q.empty()) {
            int r = q.top().second.first;
            int c = q.top().second.second;
            int cnt = q.top().first;
            q.pop();
            if('A' <= matrix[r][c] && matrix[r][c] <= 'Z' && !visit[matrix[r][c]-'A']) {
                visit[matrix[r][c]-'A'] = true;
                for(auto i: adj[matrix[r][c]-'A']) {
                    if(vis[i.first][i.second] > cnt) {
                        vis[i.first][i.second] = cnt;
                        q.push({cnt,{i.first,i.second}});
                    }
                }
            }
            for(int i = 0; i<4; i++) {
                int newrow = r+rowdiff[i];
                int newcol = c+coldiff[i];
                if(newrow >=0 && newrow < n && newcol >= 0 && newcol < m && vis[newrow][newcol] > cnt+1 && matrix[newrow][newcol] != '#') {
                    vis[newrow][newcol] = cnt+1;
                    q.push({cnt+1,{newrow,newcol}});
                }
            }
        }
        if(vis[n-1][m-1] == 1e9) return -1;
        return vis[n-1][m-1];
    }
};