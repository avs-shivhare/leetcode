class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto &i: nums) {
            mpp[i]++;
            if(mpp[i] > 1) return i;
        }
        return -1;
    }
};