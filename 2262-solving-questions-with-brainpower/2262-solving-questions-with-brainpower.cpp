class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n,0);
        for(int i = n-1; i>=0; i--) {
            long long notTake = (i+1<n ? dp[i+1]:0);
            long long take = q[i][0]+(q[i][1]+i+1 < n? dp[i+q[i][1]+1]:0);
            dp[i] = max(take,notTake);
        }
        return dp[0];
    }
};