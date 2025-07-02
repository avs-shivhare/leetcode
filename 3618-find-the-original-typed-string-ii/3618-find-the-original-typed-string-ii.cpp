class Solution {
public:
    int possibleStringCount(string word, int k) {
        vector<int> temp;
        int cnt = 1;
        int n = word.size();
        for(int i = 1; i<n; i++) {
            if(word[i-1] == word[i]) {
                cnt++;
            }
            else {
                temp.push_back(cnt);
                cnt = 1;
            }
        }
        temp.push_back(cnt);
        int mod = 1e9+7;
        long long total = 1;
        for(auto i: temp) {
            total *= (long long)i;
            total %= mod;
        }
        if(k <= temp.size()) return total;
        vector<long long> dp(k,0);
        dp[0] = 1;
        for(auto i: temp) {
            vector<long long> dp2(k,0);
            long long sum = 0;
            for(int j = 0; j<k; j++) {
                if(j > 0) sum = (sum+dp[j-1])%mod;
                if(j > i) sum = (sum-dp[j-i-1]+mod)%mod;
                dp2[j] = sum;
            }
            dp = dp2;
        }
        long long x = 0;
        for(int i = temp.size(); i<k; i++) {
            x = (x+dp[i]+mod)%mod;
        }
        return (total-x+mod)%mod;
    }
};