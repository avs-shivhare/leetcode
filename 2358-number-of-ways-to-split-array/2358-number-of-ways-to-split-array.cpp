class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for(auto i: nums) sum += i;
        long long temp = 0;
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i<n-1; i++) {
            temp += nums[i];
            sum -= nums[i];
            if(temp >= sum) ans++;
        }
        return ans;
    }
};