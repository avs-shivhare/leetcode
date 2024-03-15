class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1;
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i =0; i<n; i++) {
            ans[i] = sum;
            sum *= nums[i];
        }
        sum =1;
        for(int i = n-1; i>=0; i--) {
            ans[i]*= sum;
            sum *= nums[i];
        }
        return ans;
    }
};