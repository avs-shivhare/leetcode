class Solution {
public:
    int f(vector<int> &nums, int k) {
        int n = nums.size();
        int l =0,r=0,ans =0,sum =0;
        while(r<n) {
            sum += nums[r]%2;
            while(sum > k) sum -= nums[l++]%2;
            ans += r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};