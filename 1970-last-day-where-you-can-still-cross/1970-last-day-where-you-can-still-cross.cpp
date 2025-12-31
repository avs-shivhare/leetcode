class Solution {
public:
    bool check(vector<vector<int>> &mat,int &n,int &m,int &mid) {
        // cout<<"done"<<endl;
        // return false;
        queue<vector<int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0; i<m; i++) {
            if(mat[0][i] >= mid) {
                //cout<<0<<" "<<i<<" "<<mid<<endl;
                vis[0][i] = true;
                q.push({0,i});
            }
        }
        int rowdiff[4] = {0,0,1,-1};
        int coldiff[4] = {1,-1,0,0};
        while(!q.empty()) {
            int r = q.front()[0];
            int c = q.front()[1];
            q.pop();
            if(r == n-1) return true;
            for(int i =0; i<4; i++) {
                int nr = r+rowdiff[i];
                int nc = c+coldiff[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] >= mid && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int n, int m, vector<vector<int>>& cells) {
        vector<vector<int>> mat(n,vector<int>(m,1e9));
        int si = cells.size();
        for(int i = 0; i<si; i++) {
            //cout<<cells[i][0]-1<<" "<<cells[i][1]-1<<endl;
            mat[cells[i][0]-1][cells[i][1]-1] = i;
        }
        // for(auto i: mat) {
        //     for(auto j: i) {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        int l = 0,r = si-1;
        int ans = 0;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(check(mat,n,m,mid)) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};