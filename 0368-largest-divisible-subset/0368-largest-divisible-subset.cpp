class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1), hash(n);
        for(int i =0; i<n; i++) {
            hash[i] = i;
            for(int j =0; j<i; j++) {
                if(nums[i]%nums[j] == 0 && dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
        }
        int ans1 = -1;
        int last = -1;
        for(int i =0; i<n; i++) {
            if(dp[i] > ans1) {
                ans1 = dp[i];
                last = i;
            }
        }
        ans.push_back(nums[last]);
        
        while(hash[last] != last) {
           last = hash[last];
           ans.push_back(nums[last]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};