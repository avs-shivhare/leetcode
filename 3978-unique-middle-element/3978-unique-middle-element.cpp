class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(auto &i: nums) mpp[i]++;
        return mpp[nums[n/2]] == 1;
    }
};