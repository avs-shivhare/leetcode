class Solution {
public:
    long long dp[16][2][2];
    long long find(int i,int small,int start,string &s) {
        if(i ==s.size()) return 1;
        if(dp[i][small][start] != -1) return dp[i][small][start];
        long long ans = 0;
        int last = (small ? s[i]-'0': 9);
        for(int j = 0; j<=last; j++) {
            if(j == 0) {
                if(!start) ans += find(i+1,small && (j == last),false,s);
            }
            else ans += find(i+1,small && (j == last),true,s);
        }
        return dp[i][small][start] = ans;
    }
    long long countDistinct(long long n) {
        memset(dp,-1,sizeof(dp));
        string s = to_string(n);
        return find(0,true,false,s)-1;
    }
};