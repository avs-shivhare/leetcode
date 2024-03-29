class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        int r =0,l =0;
        long long cnt =0;
        int maxi = *max_element(nums.begin(),nums.end());
        while(r<n) {
            if(nums[r] == maxi) cnt++;
            while(cnt >= k) {
                if(nums[l] == maxi) {
                    cnt--;
                }
                l++;
            }
            ans += l;
            r++;
        }
        return ans;
    }
};