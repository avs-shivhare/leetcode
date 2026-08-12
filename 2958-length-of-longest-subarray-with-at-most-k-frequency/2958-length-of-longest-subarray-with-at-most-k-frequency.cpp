class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int l = 0, r = 0;
        int cnt = 0;
        int ans = 0;
        while(r<n) {
            if(mpp[nums[r]] == k) cnt++;
            mpp[nums[r]]++;
            while(l<r && cnt > 0) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == k) cnt--;
                l++;
            }
            if(cnt == 0) ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};