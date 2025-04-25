class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        long long cnt = 0;
        long long ans = 0;
        unordered_map<long long,long long> mpp;
        mpp[0] = 1;
        for(auto i: nums) {
            if(i%mod == k) cnt++;
            int rem = cnt%mod;
            int n = (rem-k+mod)%mod;
            ans += mpp[n];
            mpp[rem]++;
        }
        return ans;
    }
};