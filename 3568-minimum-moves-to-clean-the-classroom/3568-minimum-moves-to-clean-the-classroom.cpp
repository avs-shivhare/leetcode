class Solution {
public:
    int minMoves(vector<string>& arr, int en) {
        int n = arr.size();
        int m = arr[0].size();
        int cnt = 0;
        int sr = 0,sc = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(arr[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if(arr[i][j] == 'L') {
                    arr[i][j] = cnt+'0';
                    cnt++;
                }
            }
        }
        int total = (1<<cnt)-1;
        int dist[n][m][total+1];
        memset(dist,-1,sizeof(dist));
        dist[sr][sc][0] = en;
        queue<array<int,4>> q;
        q.push({sr,sc,0,en});
        cnt = 0;
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                int r = q.front()[0];
                int c = q.front()[1];
                int mask = q.front()[2];
                int e = q.front()[3];
                q.pop();
                if(mask == total) return cnt;
                for(int i = 0; i<4; i++) {
                    int nr = r+row[i];
                    int nc = c+col[i];
                    int ne = e-1;
                    int nm = mask;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && arr[nr][nc] != 'X' && ne >= 0) {
                        if(arr[nr][nc] == 'R') ne = en;
                        else if('0' <= arr[nr][nc] && arr[nr][nc] <= '9') {
                            nm |= 1<<(arr[nr][nc]-'0');
                        }
                        if(dist[nr][nc][nm] < ne) {
                            dist[nr][nc][nm] = ne;
                            q.push({nr,nc,nm,ne});
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};