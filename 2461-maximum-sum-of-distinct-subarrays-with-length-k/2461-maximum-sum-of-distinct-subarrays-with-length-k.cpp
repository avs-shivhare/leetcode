class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long sum = 0;
        int n = nums.size();
        int l =0,r = 0;
        int cnt = 0;
        unordered_map<int,int> mpp;
        while(r<n) {
            sum += nums[r];
            if(mpp.count(nums[r]) && mpp[nums[r]] == 1) cnt++;
            mpp[nums[r]]++;
            while(l<=r && r-l+1 > k) {
                sum -= nums[l];
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 1) cnt--;
                l++;
            }
            if(r-l+1 == k && cnt == 0) ans = max(ans,sum);
            r++;
        }
        return ans;
    }
};