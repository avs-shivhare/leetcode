class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        int l = 0,r = nums.size()-1;
        while(l<=r) {
            ans += nums[r-1];
            l++;
            r -=2;
        }
        return ans;
    }
};