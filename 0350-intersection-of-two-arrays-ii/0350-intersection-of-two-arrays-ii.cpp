class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();
        if(m < n) return intersect(nums2,nums1);
        vector<int> ans;
        unordered_map<int,int> mpp1,mpp2;
        for(int i: nums1) mpp1[i]++;
        for(int i: nums2) mpp2[i]++;
        for(auto i: mpp1) {
            if(mpp2.find(i.first) != mpp2.end()) {
                int val = i.first;
                int cnt = min(i.second,mpp2[i.first]);
                while(cnt--) {
                    ans.push_back(val);
                }
            }
        }
        return ans;
    }
};