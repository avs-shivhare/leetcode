class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for(auto &i: nums) {
            if(i&1) i = 1;
            else i = 0;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};