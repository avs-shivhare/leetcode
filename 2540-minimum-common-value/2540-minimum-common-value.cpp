class Solution {
public:
    bool find(vector<int> &nums,int &el) {
        int l = 0,r = nums.size()-1;
        while(l<=r) {
            int mid = (l+r)>>1ll;
            if(nums[mid] == el) return true;
            else if(nums[mid] < el) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(auto &i: nums1) {
            if(find(nums2,i)) return i;;
        }
        return -1;
    }
};