class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = n;
        for(int i = 0; i<n; i++) {
            int t = i;
            t += n-(upper_bound(nums.begin(),nums.end(),(long long)k*nums[i])-nums.begin());
            ans = min(ans,t);
        }
        return ans;
    }
};