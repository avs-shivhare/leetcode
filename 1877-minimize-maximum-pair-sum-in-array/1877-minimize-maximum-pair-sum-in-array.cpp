class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mini = 0;
        int l = 0,r = nums.size()-1;
        while(l<r) {
            mini = max(mini,nums[l]+nums[r]);
            l++;
            r--;
        }
        return mini;
    }
};