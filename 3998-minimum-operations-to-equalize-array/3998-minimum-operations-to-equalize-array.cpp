class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool flag = true;
        int n = nums.size();
        for(int i = 1; i<n; i++) {
            if(nums[i] != nums[i-1]) {
                flag = false;
                break;
            }
        }
        if(flag) return 0;
        return 1;
    }
};