class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long> dp(26,0);
        long long total = 0;
        int mod = 1e9+7;
        for(int i = 0; i<n; i++) {
            long long seq = (1ll*total+1-dp[s[i]-'a']+mod)%mod;
            total = (total+seq)%mod;
            dp[s[i]-'a'] += seq;
            dp[s[i]-'a'] %= mod;
        }
        return total;
    }
};