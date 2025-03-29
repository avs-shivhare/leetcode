class Solution {
public:
    int reverseDegree(string s) {
        int mod = 1e9+7;
        int n = s.size();
        long long ans = 0;
        for(int i = 0; i<n; i++) {
            ans += (26-(s[i]-'a'))*(i+1);
            ans %= mod;
        }
        return ans;
    }
};