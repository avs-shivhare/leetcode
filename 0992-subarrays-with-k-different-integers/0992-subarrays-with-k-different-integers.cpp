class Solution {
public:
    int f(vector<int> &nums,int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int l=0,r =0;
        int ans =0;
        while(r<n) {
            mpp[nums[r]]++;
            while(mpp.size() > k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            if(mpp.size() <= k) ans += r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};