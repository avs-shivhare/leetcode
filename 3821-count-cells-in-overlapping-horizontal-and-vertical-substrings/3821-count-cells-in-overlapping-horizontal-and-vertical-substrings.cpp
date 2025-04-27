class Solution {
public:
    vector<int> kmp(string s) {
        int n = s.size();
        int l = 0;
        vector<int> ans(n,0);
        for(int i = 1; i<n; i++) {
            while(l > 0 && s[i] != s[l]) l = ans[l-1];
            if(s[i] == s[l]) l++;
            ans[i] = l;
        }
        return ans;
    }
    int countCells(vector<vector<char>>& grid, string pattern) {
        int x = pattern.size();
        int n = grid.size();
        int m = grid[0].size();
        string h = "";
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                h += grid[i][j];
            }
        }
        auto hh = kmp(pattern+"#"+h);
        string v = "";
        for(int j = 0; j<m; j++) {
            for(int i = 0; i<n; i++) {
                v += grid[i][j];
            }
        }
        auto vv = kmp(pattern+"#"+v);
        int last = hh.size();
        for(int i = hh.size()-1; i>=0; i--) {
            int p = i-(x+1);
            if(hh[i] == x) {
                last = min(last,p-x);
            }
            if(last < p) h[p] = '1';
        }
        last = vv.size();
        for(int i = vv.size()-1; i>=0; i--) {
            int p = i-(x+1);
            if(vv[i] == x) {
                last = min(last,p-x);
            }
            if(last < p) v[p] = '1';
        }
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(h[i*m+j] == '1' && v[j*n+i] == '1') cnt++;
            }
        }
        return cnt;
    }
};