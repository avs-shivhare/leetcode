class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto &i: nums) mpp[i]++;
        for(auto &i: nums) {
            if((i&1) == 0 && mpp[i] == 1) return i; 
        }
        return -1;
    }
};