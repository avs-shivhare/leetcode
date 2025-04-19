class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n; i++) {
            int low = lower_bound(nums.begin(),nums.end(),lower-nums[i])-nums.begin();
            int high = upper_bound(nums.begin(),nums.end(),upper-nums[i])-nums.begin();
            high--;
            if(high <= i || low == n) continue;
            else if(low <= i && i <= high) {
                ans += high-i;
            }
            else {
                ans += high-low+1;
            }
        }
        return ans;
    }
};