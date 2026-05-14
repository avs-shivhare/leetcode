class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int maxi = 0;
        for(auto &i: nums) {
            mpp[i]++;
            maxi = max(maxi,i);
        }
        for(int i = 1; i<=maxi; i++) {
            if(mpp[i] == 0) return false;
        }
        return mpp[maxi] == 2 && nums.size() == maxi+1;
    }
};