class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = -1e9;
        for(int i = 1; i<=n; i++) {
            ans = max(ans,abs(nums[i%n]-nums[i-1]));
        }
        return ans;
    }
};