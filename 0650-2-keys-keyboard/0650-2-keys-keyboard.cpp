class Solution {
public:
    int dp[1001][1001][2];
    int find(int curr,int prev,int copy,int &n) {
        if(curr > n) return 1e9;
        if(curr == n) return 0;
        if(dp[curr][prev][copy] != -1) return dp[curr][prev][copy];
        int take = 1e9,notTake = 1e9;
        if(copy == 0) {
            take = 2+find(curr+curr,curr,1,n);
        }
        else {
            take = 1+find(curr+prev,prev,copy,n);
        }
        notTake = 2+find(curr+curr,curr,1,n);
        return dp[curr][prev][copy] = min(take,notTake);
    }
    int minSteps(int n) {
        memset(dp,-1,sizeof(dp));
        return find(1,0,0,n);
    }
};