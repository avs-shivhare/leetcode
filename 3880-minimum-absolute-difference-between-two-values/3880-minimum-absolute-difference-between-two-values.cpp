class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int last1 = 1e9;
        int last2 = 1e9;
        int ans = 1e9;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] == 1) {
                ans = min(ans,abs(i-last2));
                last1 = i;
            }
            else if(nums[i] == 2) {
                ans = min(ans,abs(i-last1));
                last2 = i;
            }
        }
        if(ans > n) return -1;
        return ans;
    }
};