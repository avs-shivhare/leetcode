class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ind = nums.size()-k;
        return nums[ind];
    }
};