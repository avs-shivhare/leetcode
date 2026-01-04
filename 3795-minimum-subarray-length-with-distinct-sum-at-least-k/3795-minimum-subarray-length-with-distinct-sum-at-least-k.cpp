class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        long long sum = 0;
        int ans = 1e9;
        int l = 0, r= 0;
        int n = nums.size();
        unordered_map<int,int> mpp;
        while(r<n) {
            if(mpp[nums[r]] == 0) sum += nums[r];
            mpp[nums[r]]++;
            while(l<=r && sum >=k) {
                ans = min(ans,r-l+1);
                if(mpp[nums[l]] == 1) sum -= nums[l];
                mpp[nums[l]]--;
                l++;
            }
            r++;
        }
        if(ans >= 1e9) return -1;
        return ans;
    }
};