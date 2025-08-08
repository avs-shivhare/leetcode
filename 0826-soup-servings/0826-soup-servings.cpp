class Solution {
public:
    vector<vector<double>> dp;
    double find(long long a,long long b) {
        if(a <= 0 && b > 0) return 1.0;
        if(a <= 0 && b <= 0) return 0.5;
        if(b <= 0 && a > 0) return 0.0;
        if(dp[a][b] != -1) return dp[a][b];
        return dp[a][b] = 0.25*(find(a-4,b)+find(a-3,b-1)+find(a-2,b-2)+find(a-1,b-3)); 
    }
    double soupServings(int n) {
        if(n >= 5000) return 1.0;
        n = ceil((double)n/25.0);
        dp.resize(n+1,vector<double>(n+1,-1));
        //memset(dp,-1.0,sizeof(dp));
        return find(n,n);
    }
};