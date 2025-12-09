class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> prefix,suffix;
        for(auto i: nums) {
            suffix[i]++;
        }
        long long ans = 0;
        int mod = 1e9+7;
        for(auto i: nums) {
            suffix[i]--;
            long long p = prefix[i*2ll];
            long long s = suffix[i*2ll];
            ans += (s*p)%mod;
            ans %= mod;
            prefix[i]++;
        }
        return ans;
    }
};