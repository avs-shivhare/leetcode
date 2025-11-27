class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long,long long> mpp;
        long long sum = 0;
        int n = nums.size();
        long long ans = LLONG_MIN;
        mpp[0] = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            int len = i+1;
            if(mpp.find(len%k) != mpp.end()) {
                ans = max(ans,sum-mpp[len%k]);
                mpp[len%k] = min(mpp[len%k],sum);
            }
            else mpp[len%k] = sum;
        }
        return ans;
    }
};