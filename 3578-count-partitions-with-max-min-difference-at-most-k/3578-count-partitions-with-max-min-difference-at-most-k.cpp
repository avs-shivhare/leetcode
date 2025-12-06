class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int mod = 1e9+7;
        int n = nums.size();
        vector<long long> dp(n+1,0);
        dp[0] = 1;
        deque<int> maxi,mini;
        int l = 0,r = 0;
        long long sum = 0;
        while(r<n) {
            while(!maxi.empty() && nums[maxi.back()] <= nums[r]) maxi.pop_back();
            while(!mini.empty() && nums[mini.back()] >= nums[r]) mini.pop_back();
            maxi.push_back(r);
            mini.push_back(r);
            while(nums[maxi.front()]-nums[mini.front()] > k) {
                if(maxi.front() == l) maxi.pop_front();
                if(mini.front() == l) mini.pop_front();
                sum = (sum-dp[l]+mod)%mod;
                l++;
            }
            sum = (sum+dp[r])%mod;
            dp[r+1] = sum;
            r++;
        }
        return dp[n];
    }
};