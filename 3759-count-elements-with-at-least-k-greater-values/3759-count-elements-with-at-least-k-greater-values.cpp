class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        int l = 0,r = 0;
        while(r<n) {
            while(r<n && nums[l] == nums[r]) r++;
            if(n-r >= k) ans += r-l;
            l = r;
        }
        return ans;
    }
};