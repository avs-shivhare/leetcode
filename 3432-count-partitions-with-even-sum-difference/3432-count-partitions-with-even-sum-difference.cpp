class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
        int sum2 = 0;
        int n = nums.size();
        for(int i = 0; i<n-1; i++) {
            sum -= nums[i];
            sum2 += nums[i];
            if((abs(sum-sum2)&1) == 0) ans++; 
        }
        return ans;
    }
};