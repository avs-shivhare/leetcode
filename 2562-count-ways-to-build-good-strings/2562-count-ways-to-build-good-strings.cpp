class Solution {
public:
    int mod = 1e9+7;
    int dp[900001][2];
    int find(int i,int j,bool take,int &zero,int &one,int &low,int &high) {
        int ans = 0;
        if(i+j > high) return 0;
        if(dp[i+j][take] != -1) return dp[i+j][take];
        if(low <= i+j && i+j <= high) ans = 1;
        ans = (find(i+zero,j,true,zero,one,low,high)+ans)%mod;
        ans = (find(i,j+one,false,zero,one,low,high)+ans)%mod;
        return dp[i+j][take] =ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,false,zero,one,low,high);
    }
};