class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto &i: nums) {
            mpp[i]++;
        }
        unordered_map<int,int> mpp2;
        for(auto &i: mpp) {
            mpp2[i.second]++;
        }
        for(auto &i: nums) {
            if(mpp2[mpp[i]] == 1) return i;
        }
        return -1;
    }
};