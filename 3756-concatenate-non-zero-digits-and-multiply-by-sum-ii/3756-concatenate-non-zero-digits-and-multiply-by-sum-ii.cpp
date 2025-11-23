class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int mod = 1e9+7;
        int n = s.size();
        vector<long long> digit(n+1,0),value(n+1,0),count(n+1,0),pow10(n+1,0);
        pow10[0] = 1;
        for(int i = 1; i<=n; i++) {
            pow10[i] = (pow10[i-1]*10ll)%mod;
        }
        for(int i = 0; i<n; i++) {
            int d = s[i]-'0';
            digit[i+1] = digit[i];
            value[i+1] = value[i];
            count[i+1] = count[i];
            if(d) {
                digit[i+1] += d;
                value[i+1] = (value[i]*10+d)%mod;
                count[i+1]++;
            }
        }
        vector<int> ans;
        for(auto i: queries) {
            int cnt = count[i[1]+1]-count[i[0]];
            long long sum = digit[i[1]+1]-digit[i[0]];
            long long x = 0;
            if(cnt) {
                x = (value[i[1]+1]-(value[i[0]]*pow10[cnt])%mod+mod)%mod;
            }
            ans.push_back((x*sum)%mod);
        }
        return ans;
    }
};