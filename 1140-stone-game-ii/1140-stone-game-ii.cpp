class Solution {
public:
    int dp[101][101];
    int find(int i,int m,vector<int> &piles,int &n) {
        if(i >= n) return 0;
        if(dp[i][m] != -1) return dp[i][m];
        int sum =0;
        int ans = INT_MIN;
        for(int x = 0 ; x<2*m && x+i < n; x++) {
            sum += piles[x+i];
            ans = max(ans,sum - find(i+x+1,max(m,x+1),piles,n));
        }
        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int n = piles.size();
        int ans =  find(0,1,piles,n);
        int sum = 0;
        for(auto i:piles) {
            sum += i;
        }
        return (sum+ans)/2;
    }
};