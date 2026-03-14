class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp,mpp2;
        for(auto &i: nums1) mpp[i]++;
        for(auto &i: nums2) mpp2[i]++;
        for(auto &i: mpp) {
            if(mpp2.find(i.first) != mpp2.end()) {
                int mini = min(i.second,mpp2[i.first]);
                i.second -= mini;
                mpp2[i.first] -= mini;
            }
        }
        int ans = 0;
        for(auto &i: mpp) {
            if(i.second == 0) continue;
            if(i.second&1) return -1;
            ans += i.second/2;
        }
        for(auto &i: mpp2) {
            if(i.second == 0) continue;
            if(i.second&1) return -1;
        }
        return ans;
    }
};