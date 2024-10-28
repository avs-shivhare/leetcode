class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        for(auto i: nums) {
            int sq = sqrt(i);
            if(sq*sq == i && mpp.count(sq)) {
                mpp[i] = mpp[sq]+1;
            }
            else {
                mpp[i] = 1;
            }
            ans = max(ans,mpp[i]);
        }
        if(ans >=2) return ans;
        return -1;
    }
};