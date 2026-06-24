class Solution {
public:
    int mod = 1e9+7;
    vector<vector<long long>> multi(vector<vector<long long>> a,vector<vector<long long>> b) {
        int n = a.size();
        vector<vector<long long>> c(n,vector<long long>(n,0));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                for(int k = 0; k<n; k++) {
                    c[i][j] = (c[i][j]+a[i][k]*b[k][j])%mod;
                }
            }
        }
        return c;
    }
    vector<vector<long long>> find(vector<vector<long long>> &a,long long b) {
        if(b <= 0) {
            int n = a.size();
            vector<vector<long long>> ans(n,vector<long long>(n,0));
            for(int i = 0; i<n; i++) ans[i][i] = 1;
            return ans;
        }
        if(b == 1) return a;
        auto ans = find(a,b>>1);
        if(b&1ll) return multi(a,multi(ans,ans));
        return multi(ans,ans);
    }
    int zigZagArrays(int n, int l, int r) {
        int m = r-l+1;
        vector<vector<long long>> a(2*m,vector<long long>(2*m,0));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<i; j++) a[i][j+m] = 1;
            for(int j = i+1; j<m; j++) a[i+m][j] = 1;
        }
        auto ans = find(a,n-1);
        long long cnt = 0;
        for(int i = 0; i<2*m; i++) {
            for(int j = 0; j<2*m; j++) {
                cnt = (cnt+ans[i][j])%mod;
            }
        }
        return cnt;
    }
};