class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9+7;
        vector<int> prefix(n,0),suffix(n,0);
        unordered_map<int,int> mpp,mpp2;
        for(int i = 0; i<n; i++) {
            prefix[i] = mpp[nums[i]*2];
            mpp[nums[i]]++;
        }
        for(int i = n-1; i>=0; i--) {
            suffix[i] = mpp2[nums[i]*2];
            mpp2[nums[i]]++;
        }
        long long ans = 0;
        for(int i = 0; i<n; i++) {
            ans += (long long)prefix[i]*(long long)suffix[i];
            ans %= mod;
        }
        return ans;
    }
};