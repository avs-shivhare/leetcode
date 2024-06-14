class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int> mpp;
        for(int i: nums) {
            mpp[i]++;
        }
        int ans = 0;
        for(auto i: mpp) {
            if(i.second > 1) {
                ans += i.second-1;
                mpp[i.first+1]+= i.second-1;
            }
        }
        return ans;
    }
};