class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        long long cnt = 0;
        for(int i =0; i<n; i++) {
            if(nums[i] == 0) cnt++;
            else {
                cnt = 0;
            }
            ans += cnt;
        }
        return ans;
    }
};