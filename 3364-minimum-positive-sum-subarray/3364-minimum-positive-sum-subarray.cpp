class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        for(int i = 0; i<n; i++) prefix[i+1] = prefix[i]+nums[i];
        int ans = 1e9;
        for(int i = 0; i<n; i++) {
            for(int j = i+l-1; j<i+r && j<n; j++) {
                if(prefix[j+1]-prefix[i] > 0) ans = min(ans,prefix[j+1]-prefix[i]);
            }
        }
        if(ans >= 1e9) return -1;
        return ans;
    }
};