class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int l = 0,r = 0;
        int n = nums.size();
        int cnt[32];
        memset(cnt,0,sizeof(cnt));
        int ans = 1e9;
        long long curr = 0;
        while(r<n) {
            for(int i =0; i<32; i++) {
                if(nums[r] & (1<<i)) {
                    cnt[i]++;
                    curr |= 1<<i;
                }
            }
            while(l<=r && curr >= k) {
                ans = min(r-l+1,ans);
                for(int i =0; i<32; i++) {
                    if(nums[l] & (1<<i)) {
                        cnt[i]--;
                        if(cnt[i] == 0) {
                            curr &= ~(1<<i);
                        }
                    }
                }
                l++;
            }
            r++;
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};