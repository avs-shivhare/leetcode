class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> cnt(32,0);
        int l = 0,r = 0;
        int n = nums.size();
        int ans = 0;
        while(r<n) {
            int dup = 0;
            for(int i = 0; i<32; i++) {
                if(nums[r] & (1<<i)) {
                    cnt[i]++;
                }
                if(cnt[i] == 2) dup++;
            }
            while(l<r && dup > 0) {
                for(int i = 0; i<32; i++) {
                    if(nums[l] & (1<<i)) {
                        cnt[i]--;
                    }
                    if(cnt[i] == 1) dup--;
                }
                l++;
            }
            if(dup == 0) {
                ans = max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};