class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int diff = 1e9;
        for(int i = 0; i<n; i++) {
            if(target == nums[i]) {
                diff = min(diff,abs(i-start));
            }
        }
        return diff;
    }
};