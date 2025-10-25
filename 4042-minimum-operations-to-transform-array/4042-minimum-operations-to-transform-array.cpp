class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int diff = 1e9;
        int el = 1e9;
        int n = nums1.size();
        for(int i = 0; i<n; i++) {
            vector<int> temp = {nums1[i],nums2[i]};
            sort(temp.begin(),temp.end());
            ans += 1ll*temp[1]-1ll*temp[0];
            if(temp[0] <= nums2[n] && nums2[n] <= temp[1]) {
                diff = 0;
                el = nums2[n];
            }
            if(abs(nums2[n]-temp[0]) < diff) {
                diff = abs(nums2[n]-temp[0]);
                el = temp[0];
            }
            if(abs(nums2[n]-temp[1]) < diff) {
                diff = abs(nums2[n]-temp[1]);
                el = temp[1];
            }
        }
        return ans+abs(nums2[n]-el)+1ll;
    }
};