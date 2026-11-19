class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return min({abs(1ll*nums[2]-nums[n-1]),abs(1ll*nums[n-3]-nums[0]),abs(1ll*nums[1]-nums[n-2])});
    }
};