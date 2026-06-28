class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        long long total = 0;
        long long ans = 0;
        int i = nums.size()-1;
        while(k-- && i >= 0) {
            total += max(1ll*nums[i],1ll*nums[i]*mul);
            mul--;
            i--;
        }
        return total;
    }
};