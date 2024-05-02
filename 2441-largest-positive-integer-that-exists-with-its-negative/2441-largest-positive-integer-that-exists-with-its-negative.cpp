class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_map<int,int> mpp;
        for(int i: nums) {
            if(mpp[-i] >0) {
                ans = max(ans,abs(i));
            }
            mpp[i]++;
        }
        return ans;
    }
};