class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int temp = 0;
        int n = nums2.size();
        for(auto i: nums2) {
            temp ^= i;
        }
        int ans = 0;
        for(auto i: nums1) {
            if(n&1) {
                ans ^= i;
            }
            ans ^= temp;
        }
        return ans;
    }
};