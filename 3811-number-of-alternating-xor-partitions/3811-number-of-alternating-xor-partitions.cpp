class Solution {
public:
    int alternatingXOR(vector<int>& nums, int t1, int t2) {
        unordered_map<int,int> mpp,mpp2;
        mpp[0] = 1;
        int cnt1 = 0,cnt2 = 0;
        int x = 0;
        int mod = 1e9+7;
        for(auto &i: nums) {
            x ^= i;
            int rem = x^t1;
            int rem2 = x^t2;
            if(mpp.find(rem) != mpp.end()) cnt2 = mpp[rem];
            else cnt2 = 0;
            if(mpp2.find(rem2) != mpp2.end()) cnt1 = mpp2[rem2];
            else cnt1 = 0;
            mpp[x] = (mpp[x]+cnt1)%mod;
            mpp2[x] = (mpp2[x]+cnt2)%mod;
        }
        return (cnt1+cnt2)%mod;
    }
};