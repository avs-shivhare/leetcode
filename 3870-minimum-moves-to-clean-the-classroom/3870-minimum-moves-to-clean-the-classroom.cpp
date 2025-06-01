class Solution {
public:
    int minMoves(vector<string>& mat, int energy) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        int sr = -1,sc = -1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(mat[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if(mat[i][j] == 'L') {
                    mat[i][j] = (char)(cnt+'0');
                    cnt++;
                }
            }
        }
        if(cnt == 0) return 0;
        int target = (1<<cnt)-1;
        int dist[21][21][1025];
        memset(dist,-1,sizeof(dist));
        queue<vector<int>> q;
        q.push({sr,sc,energy,0});
        dist[sr][sc][0] = energy;
        int step = 0;
        int rowdiff[4] = {1,-1,0,0};
        int coldiff[4] = {0,0,1,-1};
        while(!q.empty()) {
            int x = q.size();
            for(int p = 0;p<x; p++) {
                int r = q.front()[0];
                int c = q.front()[1];
                int en = q.front()[2];
                int mask = q.front()[3];
                q.pop();
                if(mask == target) return step;
                if(en == 0) continue;
                for(int i = 0; i<4; i++) {
                    int newrow = r+rowdiff[i];
                    int newcol = c+coldiff[i];
                    int newmask = mask;
                    if(newrow >= 0 && newrow < n && newcol >=0 && newcol < m && mat[newrow][newcol] != 'X') {
                        int newen = en-1;
                        if(mat[newrow][newcol] == 'R') newen = energy;
                        else if('0' <= mat[newrow][newcol] && mat[newrow][newcol] <= '9') {
                            newmask |= (1<<(mat[newrow][newcol]-'0'));
                        }
                        if(dist[newrow][newcol][newmask] < newen) {
                            dist[newrow][newcol][newmask] = newen;
                            q.push({newrow,newcol,newen,newmask});
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};