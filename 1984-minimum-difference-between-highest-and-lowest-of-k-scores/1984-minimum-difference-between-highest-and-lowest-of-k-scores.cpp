class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 1e9;
        for(int i = 0; i+k<=n; i++) {
            ans = min(ans,nums[i+k-1]-nums[i]);
        }
        if(ans == 1e9) return 0;
        return ans;
    }
};