class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i = 0,j = 0;
        int n = nums1.size();
        int m = nums2.size();
        while(i<n && j<m) {
            if(nums1[i][0] <= nums2[j][0]) {
                if(ans.empty() || ans.back()[0] != nums1[i][0]) {
                    ans.push_back({nums1[i][0],nums1[i][1]});
                }
                else {
                    ans.back()[1] += nums1[i][1];
                }
                i++;
            }
            else {
                if(ans.empty() || ans.back()[0] != nums2[j][0]) {
                    ans.push_back({nums2[j][0],nums2[j][1]});
                }
                else {
                    ans.back()[1] += nums2[j][1];
                }
                j++;
            }
        }
        while(i<n) {
            if(ans.empty() || ans.back()[0] != nums1[i][0]) {
                ans.push_back({nums1[i][0],nums1[i][1]});
            }
            else {
                ans.back()[1] += nums1[i][1];
            }
            i++;
        }
        while(j<m) {
            if(ans.empty() || ans.back()[0] != nums2[j][0]) {
                ans.push_back({nums2[j][0],nums2[j][1]});
            }
            else {
                ans.back()[1] += nums2[j][1];
            }
            j++;
        }
        return ans;
    }
};