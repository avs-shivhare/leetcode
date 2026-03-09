class Solution {
public:
    int mod = 1e9+7;
    long long dp[401][201][2];
    long long find(int i,int z,bool l,int &limit,int &zero,int &one) {
        int o = i-(zero-z);
        o = one-o;
        if(z < 0 || o < 0) return 0;
        if(z == 0 && o == 0) return 1;
        if(dp[i][z][l] != -1) return dp[i][z][l];
        long long ans = 0;
        if(l) {
            for(int j = i; j-i<min(limit,z); j++) {
                ans += find(j+1,z-(j-i+1),false,limit,zero,one);
                ans %= mod;
            }
        }
        else {
            for(int j = i; j-i<min(limit,o); j++) {
                ans += find(j+1,z,true,limit,zero,one);
                ans %= mod;
            }
        }
        return dp[i][z][l] = ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        long long ans = find(0,zero,false,limit,zero,one);
        ans += find(0,zero,true,limit,zero,one);
        ans %= mod;
        return ans;
    }
};