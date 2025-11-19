class Solution {
public:
    int findFinalValue(vector<int>& nums, int org) {
        unordered_map<int,int> mpp;
        for(auto i: nums) mpp[i]++;
        auto it = mpp.find(org);
        while(it != mpp.end()) {
            org *= 2;
            it = mpp.find(org);
        }
        return org;
    }
};