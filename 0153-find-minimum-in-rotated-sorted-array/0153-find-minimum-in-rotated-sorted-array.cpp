class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,r = nums.size()-1;
        int ans = 0;
        while(l<=r) {
            int mid = (l+r)>>1ll;
            int pmid = max(l,mid-1);
            int nmid = min(mid+1,r);
            if(nums[pmid] >= nums[mid] && nums[mid] <= nums[nmid]) {
                return nums[mid];
            }
            else if(nums[l] <= nums[mid]) {
                if(nums[mid] <= nums[r]) r = mid-1;
                else l = mid+1;
            }
            else {
                if(nums[r] <= nums[mid]) {
                    l = mid+1;
                }
                else r = mid-1;
            }
        }
        return -1;
    }
};