class Solution {
public: 
    pair<int,int> find1(int sr,int er,int sc,int ec,int k,int r,int c) {
        int diff = c-max(sc,c-k);
        c -= diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = min(er,r+k)-r;
        r += diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = min(ec,k+c)-c;
        c += diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = r-max(sr,r-k);
        r -= diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = c-max(sc,c-k);
        c -= diff;
        k -= diff;
        return {r,c};
    }
    pair<int,int> find2(int sr,int er,int sc,int ec,int k,int r,int c) {
        int diff;
        diff = min(er,r+k)-r;
        r += diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = min(ec,k+c)-c;
        c += diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = r-max(sr,r-k);
        r -= diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = c-max(sc,c-k);
        c -= diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = min(er,r+k)-r;
        r += diff;
        k -= diff;
        return {r,c};
    }
    pair<int,int> find3(int sr,int er,int sc,int ec,int k,int r,int c) {
        int diff;
        diff = min(ec,k+c)-c;
        c += diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = r-max(sr,r-k);
        r -= diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = c-max(sc,c-k);
        c -= diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = min(er,r+k)-r;
        r += diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = min(ec,k+c)-c;
        c += diff;
        k -= diff;
        return {r,c};
    }
    pair<int,int> find4(int sr,int er,int sc,int ec,int k,int r,int c) {
        int diff;
        diff = r-max(sr,r-k);
        r -= diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = c-max(sc,c-k);
        c -= diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = min(er,r+k)-r;
        r += diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = min(ec,k+c)-c;
        c += diff;
        k -= diff;
        if(k == 0) return {r,c};
        diff = r-max(sr,r-k);
        r -= diff;
        k -= diff;
        return {r,c};
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int sr = 0, er = n-1;
        int sc = 0, ec = m-1;
        vector<vector<int>> ans(n,vector<int>(m));
        while(sr <= er && sc <= ec) {
            cout<<sr<<" "<<er<<" "<<sc<<" "<<ec<<endl;
            int t = 2*(er-sr+1)+2*(ec-sc+1)-4;
            int kk = k%t;
            int ssr = sr,ssc = sc,eer = er,eec = ec;
            for(int i = ec; i>=sc; i--) {
                auto ns = find1(ssr,eer,ssc,eec,kk,sr,i);
                ans[ns.first][ns.second] = grid[sr][i];
            }
            sr++;
            for(int i = sr; i<=er; i++) {
                auto ns = find2(ssr,eer,ssc,eec,kk,i,sc);
                ans[ns.first][ns.second] = grid[i][sc];
            }
            sc++;
            for(int i = sc; i<=ec; i++) {
                auto ns = find3(ssr,eer,ssc,eec,kk,er,i);
                ans[ns.first][ns.second] = grid[er][i];
            }
            er--;
            for(int i = er; i>=sr; i--) {
                auto ns = find4(ssr,eer,ssc,eec,kk,i,ec);
                ans[ns.first][ns.second] = grid[i][ec];
            }
            ec--;
        }
        return ans;
    }
};