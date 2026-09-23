class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<long long,long long> mpp;
        long long sum = 0,ans = 1e18;
        int n = nums.size();
        mpp[0] = -1;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            if(sum == x) ans = min(ans,1ll*i+1);
            if(mpp.find(sum) == mpp.end()) mpp[sum] = i;
        }
        sum = 0;
        for(int i = n-1; i>=0; i--) {
            sum += nums[i];
            long long rem = x-sum;
            if(sum == x) ans = min(ans,1ll*n-i);
            if(mpp.find(rem) != mpp.end() && mpp[rem] < i) {
                ans = min(ans,(1ll*n-i)+(mpp[rem]+1));
            }
        }
        if(ans >= 1e18) return -1;
        return ans;
    }
};