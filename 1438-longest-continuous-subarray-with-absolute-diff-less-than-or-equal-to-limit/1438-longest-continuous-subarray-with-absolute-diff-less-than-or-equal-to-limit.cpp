class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int diff = 0;
        int n = nums.size();
        int l = 0,r = 0;
        int maxi = 1;
        map<int,int> mpp;
        while(r<n) {
            mpp[nums[r]]++;
            while(l<r && !mpp.empty()) {
                auto small = (mpp.begin());
                auto large = prev(mpp.end());
                //cout<<small.first<<" "<<large.first<<endl;
                //cout<<l<<" "<<r<<endl;
                if(abs(small->first - large->first) <= limit) break;
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};