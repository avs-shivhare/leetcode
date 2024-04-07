class Solution {
public:
    int find(vector<int> &nums,int k) {
        for(int i =0; i<nums.size(); i++) {
            if(nums[i] == k) return i;
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n,-1);
        for(int i =0; i<n; i++) {
            int ind = find(nums2,nums1[i]);
            for(int j  = ind+1; j<m; j++) {
                if(nums1[i] <nums2[j]) {
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};