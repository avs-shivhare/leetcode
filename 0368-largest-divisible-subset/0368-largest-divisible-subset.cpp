class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> dp(n,1);
        sort(nums.begin(),nums.end());
        int maxi = 0;
        int next[1001];
        int last = 0;
        memset(next,-1,sizeof(next));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[i]%nums[j] == 0 && dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1;
                    if(dp[i] > maxi) {
                        maxi = dp[i];
                        last = i;
                    }
                    next[i] = j;
                }
            }
        }
        //cout<<last<<endl;
        while(last != -1) {
            ans.push_back(nums[last]);
            last = next[last];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};