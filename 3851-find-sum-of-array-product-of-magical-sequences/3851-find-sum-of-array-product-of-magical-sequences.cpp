class Solution {
public:
    int mod = 1e9+7;
    int nck[31][31];
    int dp[31][31][51][31];
    void calnck() {
        memset(nck,0,sizeof(nck));
        for(int i = 1; i<=30; i++) {
            nck[i][0] = 1;
            nck[i][i] = 1;
            for(int j = 1; j<=i/2; j++) {
                int x = (nck[i-1][j-1]+nck[i-1][j])%mod;
                nck[i][j] = x;
                nck[i][i-j] = x;
            }
        }
    }
    int find(int m,int k,int i,long long mask,vector<int> &nums,int &n) {
        int b = __builtin_popcount(mask);
        if(m < 0 || k<0 || m+b < k) return 0;
        if(m == 0) {
            if(k == b) return 1;
            return 0;
        }
        if(i>=n) return 0;
        if(dp[m][k][i][mask] != -1) return dp[m][k][i][mask];
        long long ans = 0;
        long long poc = 1;
        int x = nums[i];
        for(int p = 0; p<=m; p++) {
            long long per = 1ll*nck[m][p]*poc%mod;
            long long newMask = mask+p;
            long long nextMask = newMask>>1;
            bool flag = newMask&1;
            ans = (ans+per*find(m-p,k-flag,i+1,nextMask,nums,n))%mod;
            poc = poc*x%mod;
        }
        return dp[m][k][i][mask] = ans;
    }
    int magicalSum(int m, int k, vector<int>& nums) {
        calnck();
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return find(m,k,0,0,nums,n);
    }
};