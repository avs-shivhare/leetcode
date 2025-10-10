class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n+k,0);
        int ans = -1e9;
        for(int i = n-1; i>=0; i--) {
            int sum = energy[i]+dp[i+k];
            dp[i] = sum;
            //cout<<i<<" "<<sum<<endl;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};