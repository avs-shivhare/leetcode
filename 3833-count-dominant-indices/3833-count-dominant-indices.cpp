class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            sum -= nums[i];
            int cnt = n-i-1;
            if(nums[i] > (double)sum/(double)cnt) ans++;
        }
        return ans;
    }
};