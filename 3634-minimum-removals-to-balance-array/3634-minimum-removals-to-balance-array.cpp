class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1e9;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n; i++) {
            int ind = upper_bound(nums.begin(),nums.end(),1ll*nums[i]*k)-nums.begin();
            ans = min(i+(n-ind),ans);
        }
        return ans;
    }
};