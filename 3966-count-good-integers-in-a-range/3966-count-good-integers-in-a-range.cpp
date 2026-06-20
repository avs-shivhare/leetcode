class Solution {
public:
    long long dp[21][2][11][2];
    long long find(int i,int tight,int zero,int last,string &s,int &k) {
        //cout<<i<<" "<<tight<<" "<<last<<endl;
        if(s.size() < 2) return 0;
        if(i >= s.size()) {
            if(zero) return 0ll;
            return 1ll;
        }
        if(dp[i][tight][last][zero] != -1) return dp[i][tight][last][zero];
        long long ans = 0;
        int nl = (tight ? s[i]-'0': 9);
        for(int j = 0; j<=nl; j++) {
            if(zero || abs(j-last) <= k) {
                ans += find(i+1,tight && (j == (s[i]-'0')),zero && j == 0,j,s,k);
            }
        }
        //if(tight) return ans;
        return dp[i][tight][last][zero] = ans;
    }
    long long cal(long long n,int k) {
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        long long ans = find(0,1,1,0,s,k);
        if(n >= 10) return ans-9; 
        return ans;
    }
    long long goodIntegers(long long l, long long r, int k) {
        return cal(r,k)-cal(l-1,k);
    }
};