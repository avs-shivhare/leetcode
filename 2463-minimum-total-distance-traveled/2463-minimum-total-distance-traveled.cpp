class Solution {
public:
    long long dp[101][101];
    long long find(int i,int j,vector<int> &r,vector<vector<int>> &f) {
        if(i >= r.size()) return 0ll;
        if(j >= f.size()) return 1e18;
        if(dp[i][j] != -1) return dp[i][j];
        long long ans = 1e18;
        long long sum = 0;
        ans = min(ans,0+find(i,j+1,r,f));
        for(int x = i; x<r.size() && x-i < f[j][1]; x++) {
            sum += abs(1ll*r[x]-f[j][0]);
            ans = min(ans,sum+find(x+1,j+1,r,f));
        }
        return dp[i][j] = ans;
    }
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        sort(r.begin(),r.end());
        sort(f.begin(),f.end());
        memset(dp,-1,sizeof(dp));
        return find(0,0,r,f);
    }
};