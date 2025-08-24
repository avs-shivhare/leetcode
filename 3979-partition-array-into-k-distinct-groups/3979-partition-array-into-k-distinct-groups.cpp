class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto i: nums) {
            mpp[i]++;
        }
        for(auto i: mpp) {
            if(i.second > nums.size()/k) return false;
        }
        return nums.size()%k == 0;
    }
};