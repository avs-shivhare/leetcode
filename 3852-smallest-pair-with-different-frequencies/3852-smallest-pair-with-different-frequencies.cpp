class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto &i: nums) mpp[i]++;
        unordered_map<int,int> mpp2;
        for(auto &i: mpp) {
            if(mpp2.find(i.second) != mpp2.end()) mpp2[i.second] = min(mpp2[i.second],i.first);
            else mpp2[i.second] = i.first;
        }
        vector<int> ans = {(int)1e9,(int)1e9};
        for(auto &i: mpp2) {
            if(ans[0] > i.second) {
                ans[1] = ans[0];
                ans[0] = i.second;
            }
            else if(ans[1] > i.second) ans[1] = i.second;
        }
        if(ans[0] == 1e9 || ans[1] == 1e9) return {-1,-1};
        return ans;
    }
};