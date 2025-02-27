class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int dp[1001][1001];
        unordered_map<int,int> mpp;
        int n =arr.size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            mpp[arr[i]] = i;
            for(int prev = 0; prev<i; prev++) {
                int diff = arr[i]-arr[prev];
                int ind = 0;
                if(mpp.count(diff)) {
                    ind = mpp[diff];
                }
                else ind = -1;
                if(diff < arr[prev] && ind >= 0) {
                    dp[i][prev] = 1+dp[prev][ind];
                }
                else dp[i][prev] = 2;
                ans = max(ans,dp[i][prev]);
            }
        }
        if(ans > 2) return ans;
        return 0;
    }
};