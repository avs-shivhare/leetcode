class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int l = 0,r = 0;
        int n = nums.size();
        int cnt = 0;
        while(r<n) {
            while(r<n && nums[l] == nums[r]) r++;
            if(l > 0 && r< n) {
                if((nums[l-1] > nums[l] && nums[l] < nums[r]) || (nums[l-1] < nums[l] && nums[l] > nums[r])) cnt++;
            }
            l = r;
        }
        return cnt;
    }
};