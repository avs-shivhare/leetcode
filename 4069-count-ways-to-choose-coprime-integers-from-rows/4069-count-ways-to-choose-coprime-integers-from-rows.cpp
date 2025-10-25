class Solution {
public:
    int dp[151][151];
    int gcd(int a,int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        if(a > b) return gcd(a%b,b);
        return gcd(a,b%a);
    }
    int mod = 1e9+7;
    int find(int i,int g,vector<vector<int>> &mat,int &n,int &m) {
        if(i == n) {
            if(g == 1) return 1;
            return 0;
        }
        if(dp[i][g] != -1) return dp[i][g];
        long long ans = 0;
        for(int j = 0; j<m; j++) {
            ans += find(i+1,(g == 0?mat[i][j]: gcd(g,mat[i][j])),mat,n,m);
            ans %= mod;
        }
        return dp[i][g] = ans;
    }
    int countCoprime(vector<vector<int>>& mat) {
        memset(dp,-1,sizeof(dp));
        int n = mat.size();
        int m = mat[0].size();
        return find(0,0,mat,n,m);
    }
};