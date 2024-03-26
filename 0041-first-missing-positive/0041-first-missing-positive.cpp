class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 && nums[0] != 1) return 1;
        bool flag = false;
        for(int i =0; i<n; i++) {
            if(nums[i] == 1) {
                flag =true;
                break;
            }
        }
        if(!flag) return 1;
        for(int i =0; i<n; i++) {
            if(nums[i] <= 0 || nums[i] >n) nums[i] = 1;
        } 
        for(int i = 0; i<n; i++) {
            if(nums[abs(nums[i])-1] > 0) nums[abs(nums[i])-1] *= -1;
        }
        for(int i =0; i<n; i++) if(nums[i] > 0) return i+1;

        return n+1;
    }
};