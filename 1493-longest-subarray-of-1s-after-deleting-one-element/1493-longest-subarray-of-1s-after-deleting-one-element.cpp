class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        int l = 0,r = 0;
        int zeroCount = 0;
        bool flag = true;
        for(int i: nums) {
            if(i == 0) {
                flag = false;
                break;
            }
        }
        if(flag) return nums.size()-1;
        while(r<n) {
            if(nums[r] == 0) {
                zeroCount++;
            }
            while(l<=r && zeroCount > 1) {
                if(nums[l] == 0) zeroCount--;
                l++;
            }
            if(zeroCount == 0) {
                maxi = max(maxi,r-l+1);
            }
            else if(zeroCount == 1) {
                maxi = max(maxi,r-l);
            }
            r++;
        }
        return maxi;
    }
};