class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i<n; i++) {
            if(nums[i-1] == nums[i]) {
                nums[i-1] *= 2;
                nums[i] = 0;
            }
        }
        int i = 0,z = 0;
        while(i<n) {
            swap(nums[i],nums[z]);
            if(nums[z] != 0) {
                z++;
            }
            i++;
        }
        return nums;
    }
};