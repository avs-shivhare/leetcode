class Solution {
public:
    long long find(vector<int> &nums) {
        long long ans = 0;
        int l = 0,r = 0;
        int n = nums.size();
        int cnt = 0;
        while(r<n) {
            if(nums[r] != 0) cnt++;
            while(l<r && cnt) {
                if(nums[l] != 0) cnt--;
                l++;
            }
            if(cnt == 0) ans += r-l+1;
            r++;
        }
        return ans;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        return find(nums);
    }
};