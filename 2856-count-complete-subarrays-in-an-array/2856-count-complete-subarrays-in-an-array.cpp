class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp,mpp2;
        for(auto i: nums) mpp[i]++;
        int l = 0,r = 0;
        int ans = 0;
        while(r<n) {
            mpp2[nums[r]]++;
            while(l<=r && mpp2.size() >= mpp.size()) {
                ans += n-r;
                mpp2[nums[l]]--;
                if(mpp2[nums[l]] == 0) mpp2.erase(nums[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};