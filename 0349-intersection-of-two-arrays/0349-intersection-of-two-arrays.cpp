class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n < m ) {
            return intersection(nums2,nums1);
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i =0,j =0;
        unordered_set<int> st;
        while(i<n && j<m) {
            if(nums1[i] == nums2[j]) {
                st.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        vector<int> ans;
        for(auto i: st) {
            ans.push_back(i);
        }
        return ans;
    }
};