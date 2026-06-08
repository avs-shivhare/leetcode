class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less,greater,equal;
        for(auto &i: nums) {
            if(i < pivot) less.push_back(i);
            else if(i > pivot) greater.push_back(i);
            else equal.push_back(i);
        }
        int n = nums.size();
        int i = 0;
        for(auto &j: less) {
            nums[i++] = j;
        }
        for(auto &j: equal) {
            nums[i++] = j;
        }
        for(auto &j: greater) {
            nums[i++] = j;
        }
        return nums;
    }
};