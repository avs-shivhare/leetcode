class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        int sum = 0;
        int l = 0, r= 0;
        int cnt = 0;
        int ans = 0;
        while(r<n) {
            if(mpp[nums[r]] == 1) cnt++;
            mpp[nums[r]]++;
            sum += nums[r];
            while(l<r && cnt > 0) {
                sum -= nums[l];
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 1) cnt--;
                l++;
            }
            if(cnt == 0) ans = max(ans,sum);
            r++;
        }
        return ans;
    }
};