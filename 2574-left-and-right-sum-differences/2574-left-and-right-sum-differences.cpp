class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int sum2 = 0;
        vector<int> ans(n,0);
        for(int i = 0; i<n; i++) {
            sum -= nums[i];
            ans[i] = abs(sum-sum2);
            sum2 += nums[i];
        }
        return ans;
    }
};