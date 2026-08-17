class Solution {
public:
    int dp[501][501];
    int find(int l,int r,vector<int> &prefix) {
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        for(int i = l+1; i<=r; i++) {
            int left = prefix[i]-prefix[l];
            int right = prefix[r+1]-prefix[i];
            if(left > right) ans = max(ans,right+find(i,r,prefix));
            else if(left < right) ans = max(ans,left+find(l,i-1,prefix));
            else {
                ans = max(ans,right+find(i,r,prefix));
                ans = max(ans,left+find(l,i-1,prefix));
            }
        }
        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n+1,0);
        for(int i = 0; i<n; i++) {
            prefix[i+1] = prefix[i]+arr[i];
        }
        memset(dp,-1,sizeof(dp));
        return find(0,n-1,prefix);
    }
};