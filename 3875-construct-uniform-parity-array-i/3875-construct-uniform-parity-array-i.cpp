class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool flag = true,flag2 = true;
        int n = nums1.size();
        unordered_map<int,int> mpp;
        for(auto &i: nums1) mpp[i%2]++;
        for(int i = 0; i<n; i++) {
            if(nums1[i]&1) {
                if(mpp[1] <= 1) flag2 = false;
            }
            else {
                if(mpp[1] == 0) flag = false;
            }
        }
        return flag || flag2;
    }
};