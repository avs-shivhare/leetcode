class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        vector<int> suffix(n,0);
        long long cnt = 0;
        for(int i =0; i<n; i++) {
            if(((nums[i]+cnt)&1) == 0) {
                if(i+k > n) return -1;
                ans++;
                cnt++;
                suffix[i+k-1]++;
            }
            cnt-= suffix[i];
        }
        return ans;
    }
};