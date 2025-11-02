class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        for(auto &i: nums) {
            i = abs(i);
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long ans = 1ll*nums[n-1]*nums[n-2]*1e5;
        return ans;
    }
};