class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mpp;
        for(auto i: nums) mpp[i]++;
        int ans = 0;
        for(auto i: mpp) {
            if(mpp.count(i.first+1)) {
                ans = max(ans,i.second+mpp[i.first+1]);
            }
        }
        return ans;
    }
};