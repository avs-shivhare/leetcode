class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n,1e9);
        mini[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--) {
            mini[i] = min(mini[i+1],nums[i]);
        }
        int maxi = -1e9;
        for(int i = 0; i<n; i++) {
            maxi = max(nums[i],maxi);
            if(maxi-mini[i] <= k) return i;
        }
        return -1;
    }
};