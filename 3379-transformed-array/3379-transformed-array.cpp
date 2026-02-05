class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i<n; i++) {
            if(nums[i] >= 0) {
                int next = (i+nums[i])%n;
                ans[i] = nums[next];
            }
            else {
                int next = abs(nums[i])%n;
                next = (i-next+n)%n;
                ans[i] = nums[next];
            }
        }
        return ans;
    }
};