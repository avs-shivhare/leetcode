class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> mpp(26,0);
        for(auto i: s) {
            mpp[i-'a']++;
        }
        int mod = 1e9+7;
        for(int j = 0; j<t; j++) {
            vector<long long> temp(26,0);
            for(int i = 0; i<26; i++) {
                if(i == 25) {
                    temp[0] += mpp[i];
                    temp[1] += mpp[i];
                    temp[0] %= mod;
                    temp[0] %= mod;
                }
                else {
                    temp[i+1] += mpp[i];
                    temp[i+1] %= mod;
                }
            }
            mpp = temp;
        }
        long long ans = 0;
        for(auto i: mpp) {
            ans += i;
            ans %= mod;
        }
        return ans;
    }
};