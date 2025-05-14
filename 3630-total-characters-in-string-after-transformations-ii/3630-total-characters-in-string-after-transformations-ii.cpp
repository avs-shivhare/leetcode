class Solution {
public:
    int mod = 1e9+7;
    vector<vector<long long>> power(vector<vector<long long>> &a,long long t) {
        vector<vector<long long>> ans(26,vector<long long>(26,0));
        for(int i = 0; i<26; i++) ans[i][i] = 1;
        while(t) {
            if(t&1) {
                ans = mutiply(a,ans);
            }
            a = mutiply(a,a);
            t >>= 1;
        }
        return ans;
    }
    vector<vector<long long>> mutiply(vector<vector<long long>> a,vector<vector<long long>> b) {
        vector<vector<long long>> ans(26,vector<long long>(26,0));
        for(int i = 0; i<26; i++) {
            for(int k = 0; k<26; k++) {
                if(a[i][k] == 0) continue;
                for(int j = 0; j<26; j++) {
                    ans[i][j] = (ans[i][j]+a[i][k]*b[k][j])%mod;
                }
            }
        }
        return ans;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<long long>> tra(26,vector<long long>(26,0));
        for(int i = 0; i<26; i++) {
            for(int j = 1; j<=nums[i]; j++) {
                tra[i][(i+j)%26]++;
            }
        }
        tra = power(tra,t);
        vector<long long> cnt(26,0);
        for(auto i: s) {
            cnt[i-'a']++;
        }
        vector<long long> temp(26,0);
        for(int i = 0; i<26; i++) {
            for(int j = 0; j<26; j++) {
                temp[j] = (temp[j]+cnt[i]*tra[i][j])%mod;
            }
        }
        long long ans = 0;
        for(auto i: temp) {
            ans += i;
            ans %= mod;
        }
        return ans;
    }
};