class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto &i: nums) {
            i *= i;
        }
        sort(nums.begin(),nums.end());
        long long ans = 0;
        int l = 0,r = nums.size()-1;
        while(l<=r) {
            if(l == r) {
                ans += nums[l];
                break;
            }
            ans += nums[r]-nums[l];
            l++;
            r--;
        }
        return ans;
    }
};