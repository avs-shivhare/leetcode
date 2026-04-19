class Solution {
public:
    int find(vector<int> &arr,int el) {
        int ans = -1;
        int l = 0, r = arr.size()-1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(arr[mid] >= el) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            int ind = find(nums2,nums1[i]);
            if(ind >= i) ans = max(ans,ind-i);
        }
        return ans;
    }
};