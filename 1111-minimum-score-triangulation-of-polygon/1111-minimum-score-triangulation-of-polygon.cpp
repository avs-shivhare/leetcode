class Solution {
public:
    int dp[51][51];
    long long find(int l,int r,vector<int> &arr) {
        if(l>=r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        long long ans = INT_MAX;
        for(int x = l+1; x<r; x++) {
            ans = min(ans,find(l,x,arr)+arr[l]*arr[r]*arr[x]+find(x,r,arr));
        } 
        if(ans == INT_MAX) return dp[l][r] = 0;
        return dp[l][r] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        return find(0,values.size()-1,values);
    }
};