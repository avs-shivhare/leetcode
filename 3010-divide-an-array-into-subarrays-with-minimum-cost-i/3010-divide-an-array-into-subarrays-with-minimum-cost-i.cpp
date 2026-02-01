class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        sort(nums.begin()+1,nums.end());
        return sum += accumulate(nums.begin()+1,nums.begin()+3,0);
    }
};