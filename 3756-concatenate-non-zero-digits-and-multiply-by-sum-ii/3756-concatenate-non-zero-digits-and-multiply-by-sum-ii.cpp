class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> pow(n+1,1), prefix(n+1,0),product(n+1,0),cnt(n+1,0);
        int mod = 1e9+7;
        for(int i = 1; i<=n; i++) {
            pow[i] = (pow[i-1]*10)%mod;
        }
        for(int i = 1; i<=n; i++) {
            prefix[i] = prefix[i-1]+(s[i-1]-'0');
            cnt[i] = cnt[i-1]+(s[i-1] != '0');
            if(s[i-1] == '0') product[i] = product[i-1];
            else product[i] = (product[i-1]*10+(s[i-1]-'0'))%mod;
        }
        vector<int> ans;
        for(auto &i: queries) {
            int l = i[0], r = i[1];
            int len = cnt[r+1]-cnt[l];
            long long start = product[l],end = product[r+1];
            long long sum = prefix[r+1]-prefix[l];
            long long temp = (end-((start*pow[len])%mod)+mod)%mod;
            ans.push_back((temp*sum)%mod);
        }
        return ans;
    }
};